#include "Tools.h"
#include <iostream>

std::vector<std::string> Tools::split(const std::string& str, const char& delimiter, int maxSplit)
{
    std::vector<std::string> tokens;
    std::string token;

    size_t pos = 0;
    size_t posNow = 0;
    int splitCount = 0;
    while (pos != str.npos)
    {
        pos = str.find(delimiter, posNow);
        token = str.substr(posNow, pos - posNow);
        posNow = pos + 1;
        splitCount++;
        if (!token.empty()) tokens.push_back(token);
        if (pos != str.npos && maxSplit > 0 && splitCount >= maxSplit)
        {
            token = str.substr(posNow, str.length());
            if (!token.empty()) tokens.push_back(token);
            break;
        }
    }

    return tokens;
}

std::vector<std::string> Tools::split(const std::string& str, const std::string& delimiter, int maxSplit)
{
    std::vector<std::string> tokens;
    std::string token;

    size_t pos = 0;
    size_t posNow = 0;
    size_t delimiterLength = delimiter.length();
    int splitCount = 0;
    while (pos != str.npos)
    {
        pos = str.find(delimiter, posNow);
        token = str.substr(posNow, pos - posNow);
        posNow = pos + delimiterLength;
        splitCount++;
        if (!token.empty()) tokens.push_back(token);
        if (pos != str.npos && maxSplit > 0 && splitCount >= maxSplit)
        {
            token = str.substr(posNow, str.length());
            if (!token.empty()) tokens.push_back(token);
            break;
        }
    }

    return tokens;
}

void Debug::printStyleSheet(QWidget* widget)
{
    std::cout << widget->styleSheet().toStdString() << std::endl;
}
