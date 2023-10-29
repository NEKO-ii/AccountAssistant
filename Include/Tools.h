#pragma once

#include <vector>
#include <string>
#include <QWidget>

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
     * \return 分割后的每部分保存在向量中返回
     */
    static std::vector<std::string> split(const std::string& str, const char& delimiter = ' ', int maxSplit = 0);

    /**
     * 分割字符串,以字符串为分割依据
     *
     * \param str 原始字符串
     * \param delimiter 分隔符,默认为空格
     * \param max_split 最大分割次数,默认为0表示无限制
     * \return 分割后的每部分保存在向量中返回
     */
    static std::vector<std::string> split(const std::string& str, const std::string& delimiter = " ", int maxSplit = 0);

    /**
     * 判断字符串是否存在于向量组中
     *
     * \param str 查询字符串
     * \param vec 目标向量组
     * \return 查询结果
     */
    static bool isStringInVector(const std::string& str, const std::vector<std::string>& vec);
};

class Debug
{
public:
    static void printStyleSheet(QWidget* widget);
};
