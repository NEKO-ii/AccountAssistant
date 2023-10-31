#include "Define.h"

Define::Define() {}
Define::~Define() {}

std::map<Define::AccountType, std::string> Define::AccountTypeLabelColor
{
    {AccountType::DEFAULT, "rgb(185, 185, 185)"},
    {AccountType::APP, "rgb(255, 170, 255)"},
    {AccountType::WEB_PAGE, "rgb(85, 255, 255)"},
    {AccountType::GAME, "rgb(170, 170, 255)"},
    {AccountType::WORK, "rgb(255, 170, 127)"},
    {AccountType::COMPANY, "rgb(170, 255, 0)"},
    {AccountType::ADMINISTRATION, "rgb(0, 255, 0)"},
    {AccountType::CARD, "rgb(170, 255, 255)"},
    {AccountType::EDUCATION, "rgb(85, 170, 255)"},
    {AccountType::LOCAL, "rgb(170, 85, 255)"},
    {AccountType::COMPRESS, "rgb(255, 255, 0)"},
    {AccountType::OTHER, "rgb(185, 185, 185)"}
};

std::map<Define::AccountType, std::string> Define::AccountTypeLabelTitle
{
    {AccountType::DEFAULT, "默认类型"},
    {AccountType::APP, "应用软件"},
    {AccountType::WEB_PAGE, "网页"},
    {AccountType::GAME, "游戏"},
    {AccountType::WORK, "生产力工具"},
    {AccountType::COMPANY, "公司账户"},
    {AccountType::ADMINISTRATION, "行政"},
    {AccountType::CARD, "卡片"},
    {AccountType::EDUCATION, "教育相关"},
    {AccountType::LOCAL, "本地/离线"},
    {AccountType::COMPRESS, "压缩文件"},
    {AccountType::OTHER, "其他"}
};
