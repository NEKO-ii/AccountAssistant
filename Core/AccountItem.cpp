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
AccountItem::AccountItem(QString customName, QString type, QString createTime, QString updateTime, QString comment, QString username, QString password, QString nickName, QString phoneNumber, QString email, QString note)
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
{}
AccountItem::~AccountItem() {}
