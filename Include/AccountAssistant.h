#pragma once

#include <QtWidgets/QMainWindow>
#include <QSystemTrayIcon>
#include "ui_AccountAssistant.h"
#include "AccountItem.h"
#include "KeyHook.h"
#include "Dialog_AccountArchiveEditor.h"

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
     * 初始化表格数据
     *
     */
    void _initData(void);
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
    /**
     * 将加密数据写入文件
     *
     */
    void _writeDataToFile(void);
    /**
     * 在表格中从上到下搜索某一列的值,输出第一次出现该值的行号,若未找到,输出值等于总行数
     *
     * \param colIndex 目标列索引
     * \param value 目标值
     */
    int _searchValueInTable(const QTableWidget* table, const int& colIndex, std::string value);
    /**
     * 弹出输入密码输入框
     *
     * \param inputCount 需要重复输入的次数
     * \return 最终确认的密码
     */
    std::string _inputPassword(const int& inputCount, bool& flag, const bool& showMsgWhenReject = false);
    /**
     * 自动根据当前状态获取密码
     *
     * \return 密码
     */
    std::string _getPassword(bool& flag, const bool& showMsgWhenReject = false);

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
    void slot_saveDataArchive(unsigned int id, AccountItem item, Dialog_AccountArchiveEditor::OpenMode mode);
};
