#include <QCloseEvent>
#include <QToolButton>
#include <QClipboard>
#include <QTimer>
#include <QInputDialog>
#include <QMessageBox>
#include <iostream>
#include <format>
#include "AccountAssistant.h"
#include "State.h"
#include "Path.h"
#include "Tools.h"
#include "EnDecryption.h"
#include "Dialog_AccountArchiveEditor.h"

AccountAssistant::AccountAssistant(QWidget* parent)
    : QMainWindow(parent)
{
    _keyHook = KeyHook();
    KeyHook::setKeyPressCallBack(std::bind(&AccountAssistant::_keyPressEventHandle, this, std::placeholders::_1));
    KeyHook::setKeyReleaseCallBack(std::bind(&AccountAssistant::_keyReleaseEventHandle, this, std::placeholders::_1));
    _ui.setupUi(this);
    _systemTrayIcon = new QSystemTrayIcon(this);
    _menu = new QMenu(this);
    _createSystemTrayIcon();
    _initWidgetState();
    _connectSlots();
    _ui.pages->setCurrentWidget(_ui.page_main);
}

AccountAssistant::~AccountAssistant() {}

void AccountAssistant::_keyPressEventHandle(int keyCode)
{
    // 调试输出
    std::cout << "KeyCode:" << keyCode << "  _FirstKeyCode:" << _firstKeyCode << "  Waiting:" << std::boolalpha << _isWaitingForSecondKey << std::endl;
    if (keyCode != _firstKeyCode) {
        if (_isWaitingForSecondKey)
        {
            _isWaitingForSecondKey = false;
            // 触发Ctrl+V组合键
            if (_firstKeyCode == VK_LCONTROL && keyCode == VK_V)
            {
                std::cout << "触发Ctrl+V组合键" << std::endl;
                QTimer::singleShot(_CLIPBOARD_FLUSH_DELAY, this, &AccountAssistant::_hotKeyPasteHandle);
                _keyBlock = false;
                _firstKeyCode = -1;
                KeyHook::disableHook();
            }
            else
            {
                std::cout << "触发失败" << std::endl;
                _keyBlock = true;
            }
        }
        else if (!_keyBlock)
        {
            _firstKeyCode = keyCode;
            _isWaitingForSecondKey = true;
            QTimer::singleShot(_KEY_COMBINATION_DECISION_DELAY, this, [this] {if (_isWaitingForSecondKey) { _keyBlock = true; _isWaitingForSecondKey = false; }});
        }
    }
}
void AccountAssistant::_keyReleaseEventHandle(int keyCode)
{
    if (keyCode == _firstKeyCode)
    {
        _keyBlock = false;
        _isWaitingForSecondKey = false;
        _firstKeyCode = -1;
    }
}

void AccountAssistant::_hotKeyPasteHandle(void)
{
    if (State::listenPasteShortcuts)
    {
        QClipboard* clipbord = QApplication::clipboard();
        clipbord->setText(State::contentWaitToWriteClipboard.c_str());
        State::listenPasteShortcuts = false;
    }
}

void AccountAssistant::closeEvent(QCloseEvent* event)
{
    if (State::settings.windowCloseAction == State::CLOSE)
    {
        event->accept();
    }
    else
    {
        event->ignore();
        this->hide();
    }
}

void AccountAssistant::_createSystemTrayIcon(void)
{
    QIcon icon = QIcon(QString::fromStdString(Path::mkpath(Path::WORK_DIR, "AccountAssistant.ico")));
    _systemTrayIcon->setIcon(icon);
    _systemTrayIcon->setToolTip(QString::fromUtf8("Account Assistant"));
    _systemTrayIcon->show();

    QAction* action_showWindow = new QAction("Show Window", _menu);
    QAction* action_settings = new QAction("Settings", _menu);
    QAction* action_quit = new QAction("Quit", _menu);
    _menu->addAction(action_showWindow);
    _menu->addSeparator();
    _menu->addAction(action_settings);
    _menu->addAction(action_quit);
    connect(action_showWindow, &QAction::triggered, this, &AccountAssistant::show);
    connect(action_settings, &QAction::triggered, this, [this] {show(); _ui.pages->setCurrentWidget(_ui.page_setting); });
    connect(action_quit, &QAction::triggered, this, &QApplication::quit);

    _systemTrayIcon->setContextMenu(_menu);

    if (State::settings.showSystemMessageWhenStart) _systemTrayIcon->showMessage("Info", "Account Assistant Started", QSystemTrayIcon::Information, _SYSTEM_MESSAGE_TIMEOUT);
}

void AccountAssistant::_initWidgetState(void)
{
    _ui.combo_accountGroup->hide();
    _ui.ledit_searchInput->setEnabled(false);
    _ui.table_resultShow->verticalHeader()->setDefaultSectionSize(_TABLE_DEFAULT_ROW_HEIGHT);
    _ui.table_resultShow->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    _ui.table_resultShow->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    _ui.table_resultShow->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    _ui.table_resultShow->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    _ui.table_resultShow->setColumnWidth(3, 30);
    _ui.table_resultShow->setColumnWidth(4, 30);
    _ui.table_resultShow->setColumnWidth(5, 70);
    _ui.table_resultShow->setColumnWidth(6, 60);
    _ui.table_resultShow->setColumnWidth(7, 60);
    _ui.table_resultShow->hideColumn(8);
}

void AccountAssistant::_connectSlots(void)
{
    // 链接菜单选项
    connect(_ui.action_option_setting, &QAction::triggered, this, [this] {_ui.pages->setCurrentWidget(_ui.page_setting); });
    connect(_ui.action_option_quit, &QAction::triggered, this, &QApplication::quit);
    // 链接按钮信号
    connect(_ui.btn_settingApply, &QPushButton::clicked, this, &AccountAssistant::slot_settingPageControl);
    connect(_ui.btn_settingConfirm, &QPushButton::clicked, this, &AccountAssistant::slot_settingPageControl);
    connect(_ui.btn_settingReject, &QPushButton::clicked, this, &AccountAssistant::slot_settingPageControl);
    connect(_ui.btn_newArchive, &QPushButton::clicked, this, &AccountAssistant::slot_newAccountArchive);
    // 链接热键监听
    // 当设置项改变时使设置改变标记为true
    connect(_ui.combo_windowCloseAction, &QComboBox::currentIndexChanged, this, &AccountAssistant::slot_setSettingChangedFlag);
    connect(_ui.check_hideMainWindowWhenStart, &QCheckBox::stateChanged, this, &AccountAssistant::slot_setSettingChangedFlag);
    connect(_ui.check_showSystemMessageWhenStart, &QCheckBox::stateChanged, this, &AccountAssistant::slot_setSettingChangedFlag);
    connect(_ui.combo_clipboardWriteContent, &QComboBox::currentIndexChanged, this, &AccountAssistant::slot_setSettingChangedFlag);
    connect(_ui.combo_clipboardWriteMode, &QComboBox::currentIndexChanged, this, &AccountAssistant::slot_setSettingChangedFlag);
    // 当前页面变化时执行特定方法
    connect(_ui.pages, &QStackedWidget::currentChanged, this, &AccountAssistant::slot_currentPageChanged);
    // 检索依据变化时执行特定方法
    connect(_ui.combo_searchRule, &QComboBox::currentIndexChanged, this, &AccountAssistant::slot_accountSearchRuleChanged);
    connect(_ui.combo_clipboardWriteContent, &QComboBox::currentIndexChanged, this, [this] {_ui.combo_clipboardWriteMode->setEnabled(_ui.combo_clipboardWriteContent->currentIndex() == 2 ? true : false); });
}

void AccountAssistant::_applySettings(void)
{
    if (_isSettingChanged) {
        State::settings.windowCloseAction = _ui.combo_windowCloseAction->currentIndex();
        State::settings.hideMainWindowWhenStart = _ui.check_hideMainWindowWhenStart->isChecked();
        State::settings.showSystemMessageWhenStart = _ui.check_showSystemMessageWhenStart->isChecked();
        State::settings.clipboardWriteContent = _ui.combo_clipboardWriteContent->currentIndex() == 0 ? "username" : _ui.combo_clipboardWriteContent->currentIndex() == 1 ? "password" : "both";
        State::settings.clipboardWriteMode = _ui.combo_clipboardWriteMode->currentIndex() == 0 ? "once" : "listen";
        // 设置应用后使设置改变标记为false
        _isSettingChanged = false;
        _isSettingSaved = false;
        _ui.btn_settingApply->setEnabled(false);
    }
}

void AccountAssistant::_addLineToResultShowTable(unsigned int id, const AccountItem& accountItem)
{
    int currentRowIndex = _ui.table_resultShow->rowCount();
    QTableWidget* table = _ui.table_resultShow;
    table->insertRow(currentRowIndex);
    table->setItem(currentRowIndex, 0, new QTableWidgetItem(accountItem.customName));
    table->setItem(currentRowIndex, 8, new QTableWidgetItem(std::to_string(id).c_str()));
    QLineEdit* ledit_username = new QLineEdit(table);
    QLineEdit* ledit_password = new QLineEdit(table);
    ledit_username->setText(tr("Username"));
    ledit_username->setReadOnly(true);
    ledit_username->setEchoMode(QLineEdit::Password);
    ledit_username->setStyleSheet("background:transparent; border:none; outline:none;");
    ledit_password->setText(tr("Password"));
    ledit_password->setReadOnly(true);
    ledit_password->setEchoMode(QLineEdit::Password);
    ledit_password->setStyleSheet("background:transparent; border:none; outline:none;");
    table->setCellWidget(currentRowIndex, 1, ledit_username);
    table->setCellWidget(currentRowIndex, 2, ledit_password);
    table->setItem(currentRowIndex, 5, new QTableWidgetItem(accountItem.type));
    QToolButton* tbtn_showAccount = new QToolButton(table);
    QToolButton* tbtn_copyAccount = new QToolButton(table);
    QPushButton* btn_accountInfo = new QPushButton(tr("详情"), table);
    QPushButton* btn_deleteAccount = new QPushButton(tr("删除"), table);
    QIcon icon_copy;
    icon_copy.addFile(QString::fromUtf8(":/icon/copy.svg"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon icon_showAndHide;
    icon_showAndHide.addFile(QString::fromUtf8(":/icon/visibility.svg"), QSize(), QIcon::Normal, QIcon::Off);
    tbtn_showAccount->setIcon(icon_showAndHide);
    tbtn_copyAccount->setIcon(icon_copy);
    table->setCellWidget(currentRowIndex, 3, tbtn_showAccount);
    table->setCellWidget(currentRowIndex, 4, tbtn_copyAccount);
    table->setCellWidget(currentRowIndex, 6, btn_accountInfo);
    table->setCellWidget(currentRowIndex, 7, btn_deleteAccount);
    connect(btn_deleteAccount, &QPushButton::clicked, this, &AccountAssistant::slot_deleteAccountArchive);
    connect(tbtn_showAccount, &QToolButton::clicked, this, &AccountAssistant::slot_switchAccountVisability);
    connect(tbtn_copyAccount, &QToolButton::clicked, this, &AccountAssistant::slot_copyAccount);
    connect(btn_accountInfo, &QPushButton::clicked, this, &AccountAssistant::slot_showAccountInfo);
}

void AccountAssistant::slot_currentPageChanged(int currentIndex)
{
    // 当前页面为设置页时依据全局设置更新页面组件状态
    if (currentIndex = _ui.pages->indexOf(_ui.page_setting))
    {
        _ui.combo_windowCloseAction->setCurrentIndex(State::settings.windowCloseAction);
        _ui.check_hideMainWindowWhenStart->setChecked(State::settings.hideMainWindowWhenStart);
        _ui.check_showSystemMessageWhenStart->setChecked(State::settings.showSystemMessageWhenStart);
        _ui.combo_clipboardWriteContent->setCurrentIndex(State::settings.clipboardWriteContent == "username" ? 0 : State::settings.clipboardWriteContent == "password" ? 1 : 2);
        _ui.combo_clipboardWriteMode->setCurrentIndex(State::settings.clipboardWriteMode == "once" ? 0 : 1);
        if (_ui.combo_clipboardWriteContent->currentIndex() != 2) _ui.combo_clipboardWriteMode->setEnabled(false);
        _ui.btn_settingApply->setEnabled(false);
    }
}
void AccountAssistant::slot_settingPageControl(void)
{
    QPushButton* btn = qobject_cast<QPushButton*>(this->sender());
    // 应用当前设置但不保存,页面保持现状
    if (btn->objectName().toStdString() == "btn_settingApply") _applySettings();
    // 应用并保存设置,返回主页面
    else if (btn->objectName().toStdString() == "btn_settingConfirm")
    {
        // 如果设置改变,执行应用设置操作
        if (_isSettingChanged) _applySettings();
        // 如果设置未保存,写入设置到文件
        if (!_isSettingSaved)
        {
            State::writeSettingsToFile();
            _isSettingSaved = true;
        }
        // 返回主页面
        _ui.pages->setCurrentWidget(_ui.page_main);
    }
    // 不改动设置,仅返回主页面
    else if (btn->objectName().toStdString() == "btn_settingReject")
    {
        _ui.pages->setCurrentWidget(_ui.page_main);
    }
}
void AccountAssistant::slot_accountSearchRuleChanged(int currentIndex)
{
    // 以账户类型为依据检索时显示类型下拉列表,隐藏输入框
    if (currentIndex == 3)
    {
        _ui.combo_accountGroup->show();
        _ui.ledit_searchInput->hide();
    }
    else
    {
        _ui.combo_accountGroup->hide();
        _ui.ledit_searchInput->show();
    }
    // 输出所有数据时禁用信息输入框
    if (currentIndex == 0) _ui.ledit_searchInput->setEnabled(false);
    else _ui.ledit_searchInput->setEnabled(true);
    // 依据选项调整提示文字
    if (currentIndex == 1) _ui.ledit_searchInput->setPlaceholderText("输入对应账户保存时设置的自定义快捷搜索名称");
    else if (currentIndex == 2) _ui.ledit_searchInput->setPlaceholderText("输入用户名");
    else _ui.ledit_searchInput->setPlaceholderText("");
}
void AccountAssistant::slot_newAccountArchive(void)
{
    // TODO: 完成新建对话框后实现该函数
    _addLineToResultShowTable(0, AccountItem(std::format("Custom Name {}", _ui.table_resultShow->rowCount() + 1).c_str(), "0:1:2", "", "", "", "", "", "", "", "", "", ""));
}
void AccountAssistant::slot_deleteAccountArchive(void)
{
    // TODO: 完成删除确认对话框后修改该函数
    // 因为点击删除按钮时表格对应的行会被聚焦,所以点击时的聚焦行就是需要删除的行
    //_ui.table_resultShow->removeRow(_ui.table_resultShow->currentRow());
    QPushButton* btn = qobject_cast<QPushButton*>(this->sender());
    if (btn == nullptr) return;
    QTableWidget* table = _ui.table_resultShow;
    QRect rect = btn->frameGeometry();
    QModelIndex index = table->indexAt(QPoint(rect.x(), rect.y()));
    table->removeRow(index.row());
}
void AccountAssistant::slot_switchAccountVisability(void)
{
    // TODO: 查看账户密码时进行身份认证
    QToolButton* btn = qobject_cast<QToolButton*>(this->sender());
    if (btn == nullptr) return;
    QTableWidget* table = _ui.table_resultShow;
    QRect rect = btn->frameGeometry();
    QModelIndex index = table->indexAt(QPoint(rect.x(), rect.y()));
    QLineEdit* ledit_username = (QLineEdit*)(table->cellWidget(index.row(), 1));
    QLineEdit* ledit_password = (QLineEdit*)(table->cellWidget(index.row(), 2));
    QLineEdit::EchoMode echoMode = ledit_username->echoMode() == QLineEdit::Password ? QLineEdit::Normal : QLineEdit::Password;
    ledit_username->setEchoMode(echoMode);
    ledit_password->setEchoMode(echoMode);
    QIcon icon;
    if (echoMode == QLineEdit::Normal)
    {
        icon.addFile(QString::fromUtf8(":/icon/visibility_off.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn->setIcon(icon);
    }
    else
    {
        icon.addFile(QString::fromUtf8(":/icon/visibility.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn->setIcon(icon);
    }
}
void AccountAssistant::slot_copyAccount(void)
{
    QToolButton* btn = qobject_cast<QToolButton*>(this->sender());
    if (btn == nullptr) return;
    QTableWidget* table = _ui.table_resultShow;
    QRect rect = btn->frameGeometry();
    QModelIndex index = table->indexAt(QPoint(rect.x(), rect.y()));
    QLineEdit* ledit_username = (QLineEdit*)(table->cellWidget(index.row(), 1));
    QLineEdit* ledit_password = (QLineEdit*)(table->cellWidget(index.row(), 2));
    // 获取剪切板对象指针
    QClipboard* clipbord = QApplication::clipboard();
    if (State::settings.clipboardWriteContent == "username") clipbord->setText(ledit_username->text());
    else if (State::settings.clipboardWriteContent == "password") clipbord->setText(ledit_password->text());
    else if (State::settings.clipboardWriteContent == "both")
    {
        if (State::settings.clipboardWriteMode == "once") clipbord->setText(std::format("{0} {1}", ledit_username->text().toStdString(), ledit_password->text().toStdString()).c_str());
        else if (State::settings.clipboardWriteMode == "listen")
        {
            clipbord->setText(ledit_username->text());
            // 将密码保存到待写入变量,等待粘贴后将其写入剪切板
            State::contentWaitToWriteClipboard = ledit_password->text().toStdString();
            // 设置粘贴快捷键监听标记
            State::listenPasteShortcuts = true;
            KeyHook::enableHook();
        }
    }
    // 修改按钮图标并禁用
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icon/done.svg"), QSize(), QIcon::Normal, QIcon::Off);
    btn->setIcon(icon);
    btn->setEnabled(false);
    // 定时器修改按钮属性
    QTimer::singleShot(3000, this, [btn] {
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/copy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn->setIcon(icon);
        btn->setEnabled(true);
        });
}
void AccountAssistant::slot_setSettingChangedFlag(void)
{
    _isSettingChanged = true;
    _ui.btn_settingApply->setEnabled(true);
}
void AccountAssistant::slot_showAccountInfo(void)
{
    //std::string test = "comment:username:password:neko:0016:::This is test note message.\nEndline test.\n\nEmpty line test.";
    //std::cout << AES::getHashCode(test) << std::endl;
    //std::cout << AES::encryptString(test, AES::generateAESKey("000", AES::hexStringToByteArray(State::aesArgs.salt), State::aesArgs.keyLength, State::aesArgs.iterationCount), AES::hexStringToByteArray(State::aesArgs.iv)) << std::endl;

    QPushButton* btn = qobject_cast<QPushButton*>(this->sender());
    if (btn == nullptr) return;
    QTableWidget* table = _ui.table_resultShow;
    QRect rect = btn->frameGeometry();
    QModelIndex index = table->indexAt(QPoint(rect.x(), rect.y()));
    unsigned int id = std::stoi(table->item(index.row(), 8)->text().toStdString());
    std::string encystr = State::data[id];
    std::vector<std::string> vec = Tools::split(encystr, "::");
    std::string hashCode = vec[4];

    bool ok;
    std::string password = QInputDialog::getText(nullptr, "输入密码", "输入密码", QLineEdit::Password, "", &ok, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint).toStdString();
    if (!ok || password.empty()) return;

    bool pass = false;
    std::string decystr;
    try {
        decystr = AES::decryptString(
            vec[5],
            AES::generateAESKey(
                password,
                AES::hexStringToByteArray(State::aesArgs.salt),
                State::aesArgs.keyLength,
                State::aesArgs.iterationCount),
            AES::hexStringToByteArray(State::aesArgs.iv));

        // 结果验证,对比该密码解密结果哈希值与原文哈希值是否吻合
        std::string hashDecy = AES::getHashCode(decystr);
        if (hashDecy == hashCode) pass = true;
        else pass = false;
    }
    catch (...) {}
    // 如果密码错误则结束
    if (!pass)
    {
        QMessageBox(QMessageBox::Icon::Information, "提示", "密码错误", QMessageBox::Ok, nullptr, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint).exec();
        return;
    }

    // 创建账户对象并写入非加密数据
    AccountItem item;
    item.customName = QString(vec[0].c_str());
    item.type = QString(vec[1].c_str());
    item.createTime = QString(vec[2].c_str());
    item.updateTime = QString(vec[3].c_str());

    // 解析解密后的字符串并向账户对象写入数据(依据数据文件格式定义,加密数据中每部分使用:分割且顺序固定)
    vec = Tools::split(decystr, ":", 0, false);
    item.comment = QString(vec[0].data());
    item.username = QString(vec[1].data());
    item.password = QString(vec[2].data());
    item.nickname = QString(vec[3].data());
    item.uid = QString(vec[4].data());
    item.phone = QString(vec[5].data());
    item.email = QString(vec[6].data());
    item.note = QString(vec[7].data());

    Dialog_AccountArchiveEditor editor = Dialog_AccountArchiveEditor(this, item);
    editor.exec();
}
