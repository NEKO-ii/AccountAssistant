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

CryptoPP::SecByteBlock AES::getRandomByteBlock(const int& blockSize)
{
    CryptoPP::SecByteBlock block = CryptoPP::SecByteBlock(blockSize);
    _rng.GenerateBlock(block, blockSize);
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

std::string AES::encryptString(const std::string& input, const CryptoPP::SecByteBlock& key, CryptoPP::SecByteBlock iv)
{
    std::string cipher;
    CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption encryptor = CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption(key.data(), key.size(), iv.data());
    CryptoPP::StringSource ss(input, true, new CryptoPP::StreamTransformationFilter(encryptor, new CryptoPP::StringSink(cipher)));
    return cipher;
}
std::string AES::decryptString(const std::string& input, const CryptoPP::SecByteBlock& key, CryptoPP::SecByteBlock iv)
{
    std::string out;
    CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption decryptor = CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption(key.data(), key.size(), iv.data());
    CryptoPP::StringSource ss(input, true, new CryptoPP::StreamTransformationFilter(decryptor, new CryptoPP::StringSink(out)));
    return out;
}
