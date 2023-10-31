#include "EnDecryption.h"

#include <iostream>
#include <hex.h>
#include <filters.h>
#include <modes.h>
#include <aes.h>
#include <cryptlib.h>
#include <pwdbased.h>
#include <hmac.h>
#include <sha.h>

CryptoPP::AutoSeededRandomPool AES::_rng = CryptoPP::AutoSeededRandomPool();

AES::AES() {}
AES::~AES() {}

CryptoPP::SecByteBlock AES::getRandomByteBlock()
{
    CryptoPP::SecByteBlock block = CryptoPP::SecByteBlock(CryptoPP::AES::BLOCKSIZE);
    _rng.GenerateBlock(block, CryptoPP::AES::BLOCKSIZE);
    return block;
}

CryptoPP::SecByteBlock AES::generateAESKey(const std::string& password, const CryptoPP::SecByteBlock& salt, const int& keyLength, const int& iterationCount)
{
    // 使用 PBKDF2 导出密钥
    CryptoPP::SecByteBlock derivedKey = CryptoPP::SecByteBlock(keyLength);
    CryptoPP::PKCS5_PBKDF2_HMAC<CryptoPP::SHA256> pbkdf2;
    pbkdf2.DeriveKey(derivedKey, derivedKey.size(), 0x00, reinterpret_cast<const CryptoPP::byte*>(password.data()), password.size(), salt.data(), salt.size(), iterationCount);
    return derivedKey;
}

std::string AES::byteArrayToHexString(const CryptoPP::SecByteBlock& byteArray)
{
    std::string hexString;
    CryptoPP::HexEncoder encoder = CryptoPP::HexEncoder(new CryptoPP::StringSink(hexString));
    encoder.Put(byteArray, byteArray.size());
    encoder.MessageEnd();
    return hexString;
}

CryptoPP::SecByteBlock AES::hexStringToByteArray(const std::string& hexString)
{
    std::string decodeString;
    CryptoPP::HexDecoder decoder = CryptoPP::HexDecoder(new CryptoPP::StringSink(decodeString));
    decoder.Put(reinterpret_cast<const CryptoPP::byte*>(hexString.data()), hexString.size());
    decoder.MessageEnd();
    CryptoPP::SecByteBlock byteArray = CryptoPP::SecByteBlock(reinterpret_cast<const CryptoPP::byte*>(decodeString.data()), decodeString.size());
    return byteArray;
}

std::string AES::encryptString(const std::string& input, const CryptoPP::SecByteBlock& key, const CryptoPP::SecByteBlock& iv)
{
    // 根据原数据长度确定缓冲区大小,缓冲区大小为块大小的整数倍
    CryptoPP::SecByteBlock cipher = CryptoPP::SecByteBlock(((input.size() + CryptoPP::AES::BLOCKSIZE) / CryptoPP::AES::BLOCKSIZE) * CryptoPP::AES::BLOCKSIZE);
    // 使用秘钥和IV向量注册AES加密器
    CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption encryptor = CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption(key.data(), key.size(), iv.data());
    // 解析数据
    CryptoPP::StringSource ss = CryptoPP::StringSource(input, true, new CryptoPP::StreamTransformationFilter(encryptor, new CryptoPP::ArraySink(cipher, cipher.size())));
    // 刷新缓冲
    ss.PumpAll();
    // 转为HexString返回
    return byteArrayToHexString(cipher);
}
std::string AES::decryptString(const std::string& input, const CryptoPP::SecByteBlock& key, const CryptoPP::SecByteBlock& iv)
{
    // 将HexString重新转为字节组
    CryptoPP::SecByteBlock cipher = hexStringToByteArray(input);
    std::string out;
    // 使用秘钥和IV向量注册解密器
    CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption decryptor = CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption(key.data(), key.size(), iv.data());
    // 解密数据
    CryptoPP::StringSource ss = CryptoPP::StringSource(cipher.data(), cipher.size(), true, new CryptoPP::StreamTransformationFilter(decryptor, new CryptoPP::StringSink(out)));
    // 刷新缓冲
    ss.PumpAll();
    // 返回原始字符串
    return out;
}

std::string AES::getHashCode(const std::string& input)
{
    CryptoPP::SHA256 hash;
    CryptoPP::SecByteBlock digest = CryptoPP::SecByteBlock(CryptoPP::SHA256::DIGESTSIZE);
    hash.CalculateDigest(digest, reinterpret_cast<const CryptoPP::byte*>(input.data()), input.size());
    return byteArrayToHexString(digest);
}
