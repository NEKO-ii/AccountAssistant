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

    bool _isSettingSaved = true;
    bool _isSettingChanged = false;

    Ui::AccountAssistantClass _ui;
    QSystemTrayIcon* _systemTrayIcon;
    QMenu* _menu;

    /**
     * 重写MainWindow关闭事件,根据设置可选隐藏或关闭
     *
     * \param event
     */
    void closeEvent(QCloseEvent* event) override;

    /**
     * 创建系统托盘图标
     *
     */
    void _createSystemTrayIcon(void);
    /**
     * 连接信号槽
     *
     */
    void _connectSlots(void);
    /**
     * 应用设置
     *
     */
    void _applySettings(void);

private slots:
    void slot_settingPageControl(void);
    void slot_currentPageChanged(int currentIndex);
};
