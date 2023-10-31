#pragma once

#include <QtWidgets/QMainWindow>
#include <QSystemTrayIcon>
#include "ui_AccountAssistant.h"
#include "AccountItem.h"
#include "KeyHook.h"

#define VK_V 0x56
#define VK_LCONTROL 0xA2 

class AccountAssistant : public QMainWindow
{
    Q_OBJECT

public:
    AccountAssistant(QWidget* parent = nullptr);
    ~AccountAssistant();

private:
    const int _SYSTEM_MESSAGE_TIMEOUT = 3000;
    const int _TABLE_DEFAULT_ROW_HEIGHT = 10;
    const int _KEY_COMBINATION_DECISION_DELAY = 600;
    const int _CLIPBOARD_FLUSH_DELAY = 50;

    bool _isSettingSaved = true;
    bool _isSettingChanged = false;
    int _firstKeyCode = -1;
    bool _isWaitingForSecondKey = false;
    bool _keyBlock = false;

    Ui::AccountAssistantClass _ui;
    QSystemTrayIcon* _systemTrayIcon;
    QMenu* _menu;
    KeyHook _keyHook;

    void _keyPressEventHandle(int keyCode);
    void _keyReleaseEventHandle(int keyCode);
    void _hotKeyPasteHandle(void);

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
     * 初始化页面组件状态
     *
     */
    void _initWidgetState(void);
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
    /**
     * 向信息展示表添加一行内容
     *
     * \param accountItem 账户存档对象
     */
    void _addLineToResultShowTable(unsigned int id, const AccountItem& accountItem);

private slots:
    void slot_settingPageControl(void);
    void slot_currentPageChanged(int currentIndex);
    void slot_accountSearchRuleChanged(int currentIndex);
    void slot_newAccountArchive(void);
    void slot_deleteAccountArchive(void);
    void slot_switchAccountVisability(void);
    void slot_copyAccount(void);
    void slot_setSettingChangedFlag(void);
    void slot_showAccountInfo(void);
};
