#include "AccountItem.h"

AccountItem::AccountItem()
    : customName(""),
    username(""),
    password(""),
    type(""),
    note(""),
    createTime(""),
    updateTime(""),
    phone(""),
    nickname(""),
    email(""),
    comment("")
{}
AccountItem::AccountItem(QString customName, QString type, QString createTime, QString updateTime, QString comment, QString username, QString password, QString nickname, QString uid, QString phone, QString email, QString note)
    : customName(customName),
    username(username),
    password(password),
    type(type),
    note(note),
    createTime(createTime),
    updateTime(updateTime),
    phone(phone),
    nickname(nickname),
    uid(uid),
    email(email),
    comment(comment)
{}
AccountItem::AccountItem(const AccountItem& item)
{
    this->customName = item.customName;
    this->type = item.type;
    this->createTime = item.createTime;
    this->updateTime = item.updateTime;
    this->comment = item.comment;
    this->username = item.username;
    this->password = item.password;
    this->nickname = item.nickname;
    this->uid = item.uid;
    this->phone = item.phone;
    this->email = item.email;
    this->note = item.note;
}
AccountItem::~AccountItem() {}
