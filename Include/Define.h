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

    static constexpr const char* SALT = "70E6F8960EE59C4CA0D024C855521526";
    static constexpr const char* IV = "9C07C6F623E7FB287833365326244648";
    static constexpr const char* KEY = "E4F986011129AE4C25CDC3533D167CD8";
    static constexpr int KEY_LENGTH = 32;
    static constexpr int ITERATION_COUNT = 1000;

private:
    Define();
    ~Define();
};
