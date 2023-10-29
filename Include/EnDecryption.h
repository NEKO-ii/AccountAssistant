#pragma once

#include <string>
#include <osrng.h>

// 禁用FIPS 140-2兼容性
#define CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2 0

namespace Core
{
    class AES;
}

class AES
{
public:
    enum BlockSize
    {
        AES_128 = 16,
        AES_192 = 24,
        AES_256 = 32
    };

    /**
     * 获取随机字节块
     *
     * \param blockSize 块大小
     * \return 字节块对象
     */
    static CryptoPP::SecByteBlock getRandomByteBlock(const int& blockSize);

    /**
     * 生成AES加密秘钥
     *
     * \param password 用户密码
     * \param salt 盐值
     * \param keyLength 秘钥长度
     * \param iterationCount 迭代次数
     * \return 字节块对象
     */
    static CryptoPP::SecByteBlock generateAESKey(const std::string& password, const CryptoPP::SecByteBlock& salt, const int& keyLength, const int& iterationCount);

    /**
     * 用于将随机生成的CryptoPP::SecByteBlock类型的数据转换为std::string类型的16进制字符串
     *
     */
    static std::string byteArrayToHexString(const CryptoPP::SecByteBlock& byteArray);
    /**
     * std::string类型的16进制字符串转换为CryptoPP::SecByteBlock类型
     *
     */
    static CryptoPP::SecByteBlock hexStringToByteArray(const std::string& hexString);

    /**
     * 加密字符串
     *
     * \param input 原始字符串
     * \param key 加密秘钥
     * \return 加密后的数据
     */
    static std::string encryptString(const std::string& input, const CryptoPP::SecByteBlock& key, CryptoPP::SecByteBlock iv);
    static std::string decryptString(const std::string& input, const CryptoPP::SecByteBlock& key, CryptoPP::SecByteBlock iv);

private:
    AES(void);
    ~AES(void);

    static CryptoPP::AutoSeededRandomPool _rng;
};
