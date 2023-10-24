#include "AccountItem.h"

AccountItem::AccountItem()
    : customName(""),
    username(""),
    password(""),
    type(""),
    note(""),
    createTime(""),
    updateTime(""),
    phoneNumber(""),
    nickName(""),
    email(""),
    comment("")
{}
AccountItem::AccountItem(QString customName, QString username, QString password, QString type, QString note, QString createTime, QString updateTime, QString phoneNumber, QString nickName, QString email, QString comment)
    : customName(customName),
    username(username),
    password(password),
    type(type),
    note(note),
    createTime(createTime),
    updateTime(updateTime),
    phoneNumber(phoneNumber),
    nickName(nickName),
    email(email),
    comment(comment)
{
}
AccountItem::~AccountItem() {}
