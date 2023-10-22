#include <QCloseEvent>
#include <iostream>
#include "AccountAssistant.h"
#include "State.h"
#include "Path.h"

AccountAssistant::AccountAssistant(QWidget* parent)
    : QMainWindow(parent)
{
    _ui.setupUi(this);
    _systemTrayIcon = new QSystemTrayIcon(this);
    _menu = new QMenu(this);
    _createSystemTrayIcon();
    _connectSlots();
    _ui.pages->setCurrentWidget(_ui.page_main);
}

AccountAssistant::~AccountAssistant() {}

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

    _systemTrayIcon->showMessage("Info", "Account Assistant Started", QSystemTrayIcon::Information, SYSTEM_MESSAGE_TIMEOUT);
}

void AccountAssistant::_connectSlots(void)
{
    // 链接菜单选项
    connect(_ui.action_setting, &QAction::triggered, this, [this] {_ui.pages->setCurrentWidget(_ui.page_setting); });
    connect(_ui.action_quit, &QAction::triggered, this, &QApplication::quit);
    // 链接按钮信号
    connect(_ui.btn_settingApply, &QPushButton::clicked, this, &AccountAssistant::slot_settingPageControl);
    connect(_ui.btn_settingConfirm, &QPushButton::clicked, this, &AccountAssistant::slot_settingPageControl);
    connect(_ui.btn_settingReject, &QPushButton::clicked, this, &AccountAssistant::slot_settingPageControl);
    // 当设置项改变时使设置改变标记为true
    connect(_ui.combo_windowCloseAction, &QComboBox::currentIndexChanged, this, [this] {_isSettingChanged = true; _ui.btn_settingApply->setEnabled(true); });
    connect(_ui.check_hideOnStart, &QCheckBox::stateChanged, this, [this] {_isSettingChanged = true; _ui.btn_settingApply->setEnabled(true); });
    // 页面转到设置页时执行特定方法
    connect(_ui.pages, &QStackedWidget::currentChanged, this, &AccountAssistant::slot_currentPageChanged);
}

void AccountAssistant::_applySettings(void)
{
    if (_isSettingChanged) {
        State::settings.windowCloseAction = _ui.combo_windowCloseAction->currentIndex();
        State::settings.hideOnStart = _ui.check_hideOnStart->isChecked();
        // 设置应用后使设置改变标记为false
        _isSettingChanged = false;
        _isSettingSaved = false;
        _ui.btn_settingApply->setEnabled(false);
    }
}

void AccountAssistant::slot_currentPageChanged(int currentIndex)
{
    // 当前页面为设置页时依据全局设置更新页面组件状态
    if (currentIndex = _ui.pages->indexOf(_ui.page_setting))
    {
        _ui.combo_windowCloseAction->setCurrentIndex(State::settings.windowCloseAction);
        _ui.check_hideOnStart->setChecked(State::settings.hideOnStart);
        _ui.btn_settingApply->setEnabled(false);
    }
}

void AccountAssistant::slot_settingPageControl(void)
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
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
