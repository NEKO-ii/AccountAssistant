#pragma once
#include <QString>

namespace Core
{
    class AccountItem;
}

class AccountItem
{
public:
    QString customName;
    QString username;
    QString password;
    QString type;
    QString note;
    QString createTime;
    QString updateTime;
    QString phoneNumber;
    QString nickName;
    QString email;
    QString comment;

    AccountItem();
    AccountItem(QString customName = "", QString username = "", QString password = "", QString type = "", QString note = "", QString createTime = "", QString updateTime = "", QString phoneNumber = "", QString nickName = "", QString email = "", QString comment = "");
    ~AccountItem();
};
