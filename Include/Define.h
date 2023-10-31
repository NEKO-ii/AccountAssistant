#pragma once

#include <map>
#include <string>

namespace Core
{
    class Define;
}

class Define
{
public:
    enum struct AccountType { DEFAULT, APP, WEB_PAGE, GAME, WORK, COMPANY, ADMINISTRATION, CARD, EDUCATION, LOCAL, COMPRESS, OTHER };
    static std::map<AccountType, std::string> AccountTypeLabelColor;
    static std::map<AccountType, std::string> AccountTypeLabelTitle;

private:
    Define();
    ~Define();
};
