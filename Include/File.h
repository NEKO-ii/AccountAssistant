#pragma once

#include <iostream>
#include <fstream>
#include <vector>

namespace Core
{
    class File;
}

class File
{
public:
    /**
     * 构造函数,初始化文件流对象
     *
     * \param path 文件路径
     * \param openMode 打开模式,默认为只读模式(ios::in)
     */
    File(const std::string& path, std::ios_base::openmode openMode = std::ios::in);
    ~File();

    /**
     * 更新文件流对象
     *
     * \param path 文件路径
     * \param openMode 打开模式
     */
    void update(const std::string& path, std::ios_base::openmode openMode = std::ios::in);
    /**
     * 关闭文件流对象
     *
     */
    inline void close(void) { if (_fs.is_open())  _fs.close(); }

    /**
     * 读取完整文件内容
     *
     * \param seekToBegin 是否自动将光标移动到起始位置,默认为是
     * \return 读取内容
     */
    std::string read(bool seekToBegin = true);
    /**
     * 读取一行,不保留行尾换行符
     *
     * \param skipCommentLine 跳过注释行
     * \param commentLineFlag 注释行标记,以该字符起始的行都将视为注释行,默认为"# ",注意空格
     * \param seekToBegin 是否自动将光标移动到起始位置,默认为是
     * \return 读取内容
     */
    std::string readLine(bool skipCommentLine = false, const std::string& commentLineFlag = "# ", bool seekToBegin = true);
    /**
     * 逐行读取文件
     *
     * \param skipCommentLine 跳过注释行
     * \param commentLineFlag 注释行标记,以该字符起始的行都将视为注释行,默认为"# ",注意空格
     * \param ignoreEmptyLines 是否忽略空行,默认为是
     * \param preserveLineBreaks 是否保留换行符,默认为否
     * \param seekToBegin 是否自动将光标移动到起始位置,默认为是
     * \return 行内容列表
     */
    std::vector<std::string> readLines(bool skipCommentLine = false, const std::string& commentLineFlag = "# ", bool ignoreEmptyLines = true, bool preserveLineBreaks = false, bool seekToBegin = true);
    /**
     * 将字符串写入文件
     *
     * \param content 待写入字符串内容
     */
    void write(const std::string& content, bool seekToBegin = false);
    /**
     * 向文件写入一行
     *
     * \param line 待写入内容
     * \param appendLineBreak 自动在行末尾添加换行符
     */
    void writeLine(const std::string& line, bool appendLineBreak = false, bool seekToBegin = false);
    /**
     * 向文件写入多行
     *
     * \param lines 待写入内容组
     * \param appendLineBreaks 自动在每行末尾添加换行符
     */
    void writeLines(const std::vector<std::string>& lines, bool appendLineBreaks = false, bool seekToBegin = false);

private:
    static constexpr std::size_t _BUFF_SIZE = 10;

    bool _isOpen;

    std::fstream _fs;
    std::string _path;
    std::string _mode;

    /**
     * 检查文件流是否打开,并在未打开时输出错误
     *
     * \return 检查结果
     */
    inline bool _check(const std::string& mode)
    {
        if (_isOpen)
        {
            if (_mode == "both") return true;
            if (mode == _mode) return true;
            else
            {
                std::cerr << "The file open mode does not support this operation. Current mode: " << _mode << std::endl;
                return false;
            }
        }
        else
        {
            std::cerr << "File stream not open." << std::endl;
            return false;
        }
    }
    /**
     * 清除标记并将光标移动到起始位置
     *
     */
    inline void _seekToBegin(void)
    {
        _fs.clear();
        _fs.seekg(std::ios::beg);
        _fs.seekp(std::ios::beg);
    }
    /**
     * 检查是否含有BOM标识
     *
     * \param decKrc 字符串
     * \param decKrcLen 长度
     */
    inline bool _hasBom(const char* decKrc, uint32_t decKrcLen)
    {
        if (decKrcLen >= 3
            && (unsigned char)decKrc[0] == 0xef
            && (unsigned char)decKrc[1] == 0xbb
            && (unsigned char)decKrc[2] == 0xbf)
        {
            return true;
        }
        else return false;
    }
};
