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
    QString type;
    QString createTime;
    QString updateTime;
    QString comment;
    QString username;
    QString password;
    QString nickname;
    QString uid;
    QString phone;
    QString email;
    QString note;

    AccountItem();
    AccountItem(QString customName, QString type, QString createTime, QString updateTime, QString comment, QString username, QString password, QString nickname, QString uid, QString phone, QString email, QString note);
    AccountItem(const AccountItem& item);
    ~AccountItem();
};
