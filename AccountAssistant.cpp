#include <QCloseEvent>
#include "AccountAssistant.h"
#include "State.h"
#include "Path.h"

AccountAssistant::AccountAssistant(QWidget* parent)
    : QMainWindow(parent)
{
    _ui.setupUi(this);
    _systemTrayIcon = new QSystemTrayIcon(this);
    _menu = new QMenu(this);
    createSystemTrayIcon();
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

void AccountAssistant::createSystemTrayIcon(void)
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
    connect(action_quit, &QAction::triggered, this, &QApplication::quit);

    _systemTrayIcon->setContextMenu(_menu);

    _systemTrayIcon->showMessage("Info", "Account Assistant Started", QSystemTrayIcon::Information, SYSTEM_MESSAGE_TIMEOUT);
}
