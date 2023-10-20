#include <format>
#include <string>
#include "File.h"

File::File(std::string path, std::ios_base::openmode openMode)
{
    _path = path;
    _fs.open(path, openMode);
    if (_fs.is_open())
    {
        _isOpen = true;
        if ((openMode & std::fstream::in) && (openMode & std::fstream::out)) _mode = "both";
        else if (openMode & std::fstream::in) _mode = "read";
        else if (openMode & std::fstream::out) _mode = "write";
        else _mode = "none";
    }
    else
    {
        _isOpen = false;
        std::cerr << std::format("Failed Open File: {}", path) << std::endl;
    }
}

File::~File()
{
    if (_fs.is_open())  _fs.close();
}

void File::update(std::string path, std::ios_base::openmode openMode)
{
    _path = path;
    if (_fs.is_open())  _fs.close();
    _fs.open(path, openMode);
    if (_fs.is_open())
    {
        _isOpen = true;
        if ((openMode & std::fstream::in) && (openMode & std::fstream::out)) _mode = "both";
        else if (openMode & std::fstream::in) _mode = "read";
        else if (openMode & std::fstream::out) _mode = "write";
        else _mode = "none";
    }
    else
    {
        _isOpen = false;
        std::cerr << std::format("Failed Open File: {}", path) << std::endl;
    }
}

std::string File::read(bool seekToBegin)
{
    if (!_check("read")) return std::string();
    if (seekToBegin) _seekToBegin();

    std::string content;
    std::string buff;
    while (std::getline(_fs, buff))
    {
        if (!_fs.eof()) buff += "\n";
        content.append(buff);
    }
    if (_hasBom(content.c_str(), content.length())) content = content.substr(3);
    return content;
}

std::string File::readLine(bool skipCommentLine, const std::string& commentLineFlag, bool seekToBegin)
{
    if (!_check("read")) return std::string();
    if (seekToBegin) _seekToBegin();

    std::string line;
    bool bomChecked = false;
    while (std::getline(_fs, line))
    {
        if (!bomChecked)
        {
            if (_hasBom(line.c_str(), line.length())) line = line.substr(3);
            bomChecked = true;
        }
        if (skipCommentLine && line.substr(0, commentLineFlag.length()) == commentLineFlag) continue;
        else return line;
    }
    return std::string("");
}

std::vector<std::string> File::readLines(bool skipCommentLine, const std::string& commentLineFlag, bool ignoreEmptyLines, bool preserveLineBreaks, bool seekToBegin)
{
    if (!_check("read")) return std::vector<std::string>();
    if (seekToBegin) _seekToBegin();

    std::vector<std::string> lines;
    std::string line;
    bool bomChecked = false;
    while (std::getline(_fs, line))
    {
        if (!bomChecked)
        {
            if (_hasBom(line.c_str(), line.length())) line = line.substr(3);
            bomChecked = true;
        }
        if (ignoreEmptyLines && line.empty()) continue;
        if (skipCommentLine && line.substr(0, commentLineFlag.length()) == commentLineFlag) continue;
        if (preserveLineBreaks && !_fs.eof()) line += "\n";
        lines.insert(lines.end(), line);
    }

    return lines;
}

void File::write(const std::string& content)
{
    if (!_check("write")) return;
    _fs.write(content.c_str(), content.size());
}

void File::writeLine(const std::string& line, bool appendLineBreak)
{
    if (!_check("write")) return;
}

void File::writeLines(const std::vector<std::string>& lines, bool appendLineBreaks)
{
    if (!_check("write")) return;
}
