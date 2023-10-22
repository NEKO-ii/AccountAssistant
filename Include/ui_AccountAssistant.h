/********************************************************************************
** Form generated from reading UI file 'AccountAssistant.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTASSISTANT_H
#define UI_ACCOUNTASSISTANT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountAssistantClass
{
public:
    QAction *action_setting;
    QAction *action_quit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *pages;
    QWidget *page_main;
    QWidget *page_setting;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scroll_settingOptionsContainer;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout;
    QLabel *lb_windowCLoseAction;
    QComboBox *combo_windowCloseAction;
    QLabel *lb_hideOnStart;
    QCheckBox *check_hideOnStart;
    QHBoxLayout *layout_settingPageButtonBox;
    QSpacerItem *hs_1;
    QPushButton *btn_settingReject;
    QPushButton *btn_settingConfirm;
    QPushButton *btn_settingApply;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *AccountAssistantClass)
    {
        if (AccountAssistantClass->objectName().isEmpty())
            AccountAssistantClass->setObjectName(QString::fromUtf8("AccountAssistantClass"));
        AccountAssistantClass->resize(800, 500);
        action_setting = new QAction(AccountAssistantClass);
        action_setting->setObjectName(QString::fromUtf8("action_setting"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        action_setting->setIcon(icon);
        action_quit = new QAction(AccountAssistantClass);
        action_quit->setObjectName(QString::fromUtf8("action_quit"));
        centralWidget = new QWidget(AccountAssistantClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pages = new QStackedWidget(centralWidget);
        pages->setObjectName(QString::fromUtf8("pages"));
        page_main = new QWidget();
        page_main->setObjectName(QString::fromUtf8("page_main"));
        pages->addWidget(page_main);
        page_setting = new QWidget();
        page_setting->setObjectName(QString::fromUtf8("page_setting"));
        verticalLayout_2 = new QVBoxLayout(page_setting);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scroll_settingOptionsContainer = new QScrollArea(page_setting);
        scroll_settingOptionsContainer->setObjectName(QString::fromUtf8("scroll_settingOptionsContainer"));
        scroll_settingOptionsContainer->setFrameShape(QFrame::NoFrame);
        scroll_settingOptionsContainer->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 782, 428));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        lb_windowCLoseAction = new QLabel(scrollAreaWidgetContents);
        lb_windowCLoseAction->setObjectName(QString::fromUtf8("lb_windowCLoseAction"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lb_windowCLoseAction);

        combo_windowCloseAction = new QComboBox(scrollAreaWidgetContents);
        combo_windowCloseAction->addItem(QString());
        combo_windowCloseAction->addItem(QString());
        combo_windowCloseAction->setObjectName(QString::fromUtf8("combo_windowCloseAction"));

        formLayout->setWidget(0, QFormLayout::FieldRole, combo_windowCloseAction);

        lb_hideOnStart = new QLabel(scrollAreaWidgetContents);
        lb_hideOnStart->setObjectName(QString::fromUtf8("lb_hideOnStart"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lb_hideOnStart);

        check_hideOnStart = new QCheckBox(scrollAreaWidgetContents);
        check_hideOnStart->setObjectName(QString::fromUtf8("check_hideOnStart"));

        formLayout->setWidget(1, QFormLayout::FieldRole, check_hideOnStart);

        scroll_settingOptionsContainer->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scroll_settingOptionsContainer);

        layout_settingPageButtonBox = new QHBoxLayout();
        layout_settingPageButtonBox->setSpacing(6);
        layout_settingPageButtonBox->setObjectName(QString::fromUtf8("layout_settingPageButtonBox"));
        hs_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_settingPageButtonBox->addItem(hs_1);

        btn_settingReject = new QPushButton(page_setting);
        btn_settingReject->setObjectName(QString::fromUtf8("btn_settingReject"));

        layout_settingPageButtonBox->addWidget(btn_settingReject);

        btn_settingConfirm = new QPushButton(page_setting);
        btn_settingConfirm->setObjectName(QString::fromUtf8("btn_settingConfirm"));

        layout_settingPageButtonBox->addWidget(btn_settingConfirm);

        btn_settingApply = new QPushButton(page_setting);
        btn_settingApply->setObjectName(QString::fromUtf8("btn_settingApply"));

        layout_settingPageButtonBox->addWidget(btn_settingApply);


        verticalLayout_2->addLayout(layout_settingPageButtonBox);

        pages->addWidget(page_setting);

        verticalLayout->addWidget(pages);

        AccountAssistantClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AccountAssistantClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        AccountAssistantClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_setting);
        menu->addSeparator();
        menu->addAction(action_quit);

        retranslateUi(AccountAssistantClass);

        pages->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AccountAssistantClass);
    } // setupUi

    void retranslateUi(QMainWindow *AccountAssistantClass)
    {
        AccountAssistantClass->setWindowTitle(QCoreApplication::translate("AccountAssistantClass", "AccountAssistant", nullptr));
        action_setting->setText(QCoreApplication::translate("AccountAssistantClass", "\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        action_setting->setToolTip(QCoreApplication::translate("AccountAssistantClass", "\350\207\252\345\256\232\344\271\211\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        action_quit->setText(QCoreApplication::translate("AccountAssistantClass", "\351\200\200\345\207\272", nullptr));
        lb_windowCLoseAction->setText(QCoreApplication::translate("AccountAssistantClass", "\345\205\263\351\227\255\346\214\211\351\222\256\350\241\214\344\270\272", nullptr));
        combo_windowCloseAction->setItemText(0, QCoreApplication::translate("AccountAssistantClass", "\346\234\200\345\260\217\345\214\226", nullptr));
        combo_windowCloseAction->setItemText(1, QCoreApplication::translate("AccountAssistantClass", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));

        lb_hideOnStart->setText(QCoreApplication::translate("AccountAssistantClass", "\345\220\257\345\212\250\346\227\266\351\232\220\350\227\217\344\270\273\347\252\227\345\217\243", nullptr));
        check_hideOnStart->setText(QString());
        btn_settingReject->setText(QCoreApplication::translate("AccountAssistantClass", "\345\217\226\346\266\210", nullptr));
        btn_settingConfirm->setText(QCoreApplication::translate("AccountAssistantClass", "\347\241\256\350\256\244", nullptr));
        btn_settingApply->setText(QCoreApplication::translate("AccountAssistantClass", "\345\272\224\347\224\250", nullptr));
        menu->setTitle(QCoreApplication::translate("AccountAssistantClass", "\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountAssistantClass: public Ui_AccountAssistantClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTASSISTANT_H
