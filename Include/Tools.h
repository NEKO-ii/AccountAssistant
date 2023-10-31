#pragma once

#include <vector>
#include <string>
#include <QWidget>
#include <algorithm>

namespace Core
{
    class Tools;
    class Debug;
}

class Tools
{
public:
    /**
     * 分割字符串,以字符为分割依据
     *
     * \param str 原始字符串
     * \param delimiter 分隔符,默认为空格
     * \param max_split 最大分割次数,默认为0表示无限制
     * \param ignoreEmptyStr 忽略连续分隔符出现时产生的空字符串,默认为true
     * \return 分割后的每部分保存在向量中返回
     */
    static std::vector<std::string> split(const std::string& str, const char& delimiter = ' ', int maxSplit = 0, bool ignoreEmptyStr = true);

    /**
     * 分割字符串,以字符串为分割依据
     *
     * \param str 原始字符串
     * \param delimiter 分隔符,默认为空格
     * \param max_split 最大分割次数,默认为0表示无限制
     * \param ignoreEmptyStr 忽略连续分隔符出现时产生的空字符串,默认为true
     * \return 分割后的每部分保存在向量中返回
     */
    static std::vector<std::string> split(const std::string& str, const std::string& delimiter = " ", int maxSplit = 0, bool ignoreEmptyStr = true);

    /**
     * 判断字符串是否存在于向量组中
     *
     * \param str 查询字符串
     * \param vec 目标向量组
     * \return 查询结果
     */
    template<typename T>
    static bool isInVector(const T& value, const std::vector<T>& vec)
    {
        return std::find(vec.begin(), vec.end(), value) != vec.end();
    }
};

class Debug
{
public:
    static void printStyleSheet(QWidget* widget);
};
