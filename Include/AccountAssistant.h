#pragma once

#include <QtWidgets/QMainWindow>
#include <QSystemTrayIcon>
#include "ui_AccountAssistant.h"

class AccountAssistant : public QMainWindow
{
    Q_OBJECT

public:
    AccountAssistant(QWidget* parent = nullptr);
    ~AccountAssistant();

private:
    const int SYSTEM_MESSAGE_TIMEOUT = 3000;

    Ui::AccountAssistantClass _ui;
    QSystemTrayIcon* _systemTrayIcon;
    QMenu* _menu;

    void closeEvent(QCloseEvent* event);

    /**
     * 创建系统托盘图标
     *
     */
    void createSystemTrayIcon(void);
};
