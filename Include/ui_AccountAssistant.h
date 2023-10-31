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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountAssistantClass
{
public:
    QAction *action_option_setting;
    QAction *action_option_quit;
    QAction *action_file_import;
    QAction *action_file_export;
    QAction *action_security_setting;
    QAction *action_option_accountGroupSetting;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *pages;
    QWidget *page_main;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_searchAccount;
    QComboBox *combo_searchRule;
    QComboBox *combo_accountGroup;
    QLineEdit *ledit_searchInput;
    QPushButton *btn_doSearch;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_resultCount_tip;
    QLabel *lb_resultCount_value;
    QSpacerItem *horizontalSpacer;
    QLabel *lb_lastSyncTime_tip;
    QLabel *lb_lastSyncTime_value;
    QPushButton *btn_remoteSync;
    QPushButton *btn_newArchive;
    QTableWidget *table_resultShow;
    QWidget *page_setting;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scroll_settingOptionsContainer;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *layout_settingPageOptions_1;
    QLabel *lb_windowCLoseAction;
    QComboBox *combo_windowCloseAction;
    QCheckBox *check_hideMainWindowWhenStart;
    QCheckBox *check_showSystemMessageWhenStart;
    QHBoxLayout *layout_settingPageOptions_2;
    QLabel *lb_clipboardWriteContent;
    QComboBox *combo_clipboardWriteContent;
    QLabel *lb_clipboardWriteMode;
    QComboBox *combo_clipboardWriteMode;
    QToolButton *tbtn_clipboardWriteHelp;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *layout_settingPageButtonBox;
    QSpacerItem *hs_1;
    QPushButton *btn_settingReject;
    QPushButton *btn_settingConfirm;
    QPushButton *btn_settingApply;
    QMenuBar *menuBar;
    QMenu *menu_option;
    QMenu *menu_file;
    QMenu *menu_safe;

    void setupUi(QMainWindow *AccountAssistantClass)
    {
        if (AccountAssistantClass->objectName().isEmpty())
            AccountAssistantClass->setObjectName(QString::fromUtf8("AccountAssistantClass"));
        AccountAssistantClass->resize(800, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AccountAssistantClass->sizePolicy().hasHeightForWidth());
        AccountAssistantClass->setSizePolicy(sizePolicy);
        AccountAssistantClass->setMinimumSize(QSize(800, 500));
        AccountAssistantClass->setMaximumSize(QSize(800, 500));
        action_option_setting = new QAction(AccountAssistantClass);
        action_option_setting->setObjectName(QString::fromUtf8("action_option_setting"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/settings.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_option_setting->setIcon(icon);
        action_option_quit = new QAction(AccountAssistantClass);
        action_option_quit->setObjectName(QString::fromUtf8("action_option_quit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/power.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_option_quit->setIcon(icon1);
        action_file_import = new QAction(AccountAssistantClass);
        action_file_import->setObjectName(QString::fromUtf8("action_file_import"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/upload.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_import->setIcon(icon2);
        action_file_export = new QAction(AccountAssistantClass);
        action_file_export->setObjectName(QString::fromUtf8("action_file_export"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/download.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_export->setIcon(icon3);
        action_security_setting = new QAction(AccountAssistantClass);
        action_security_setting->setObjectName(QString::fromUtf8("action_security_setting"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/lock.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_security_setting->setIcon(icon4);
        action_option_accountGroupSetting = new QAction(AccountAssistantClass);
        action_option_accountGroupSetting->setObjectName(QString::fromUtf8("action_option_accountGroupSetting"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/label.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_option_accountGroupSetting->setIcon(icon5);
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
        verticalLayout_3 = new QVBoxLayout(page_main);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lb_searchAccount = new QLabel(page_main);
        lb_searchAccount->setObjectName(QString::fromUtf8("lb_searchAccount"));

        horizontalLayout->addWidget(lb_searchAccount);

        combo_searchRule = new QComboBox(page_main);
        combo_searchRule->addItem(QString());
        combo_searchRule->addItem(QString());
        combo_searchRule->addItem(QString());
        combo_searchRule->addItem(QString());
        combo_searchRule->setObjectName(QString::fromUtf8("combo_searchRule"));

        horizontalLayout->addWidget(combo_searchRule);

        combo_accountGroup = new QComboBox(page_main);
        combo_accountGroup->setObjectName(QString::fromUtf8("combo_accountGroup"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(combo_accountGroup->sizePolicy().hasHeightForWidth());
        combo_accountGroup->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(combo_accountGroup);

        ledit_searchInput = new QLineEdit(page_main);
        ledit_searchInput->setObjectName(QString::fromUtf8("ledit_searchInput"));

        horizontalLayout->addWidget(ledit_searchInput);

        btn_doSearch = new QPushButton(page_main);
        btn_doSearch->setObjectName(QString::fromUtf8("btn_doSearch"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/search.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_doSearch->setIcon(icon6);

        horizontalLayout->addWidget(btn_doSearch);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lb_resultCount_tip = new QLabel(page_main);
        lb_resultCount_tip->setObjectName(QString::fromUtf8("lb_resultCount_tip"));

        horizontalLayout_2->addWidget(lb_resultCount_tip);

        lb_resultCount_value = new QLabel(page_main);
        lb_resultCount_value->setObjectName(QString::fromUtf8("lb_resultCount_value"));

        horizontalLayout_2->addWidget(lb_resultCount_value);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lb_lastSyncTime_tip = new QLabel(page_main);
        lb_lastSyncTime_tip->setObjectName(QString::fromUtf8("lb_lastSyncTime_tip"));

        horizontalLayout_2->addWidget(lb_lastSyncTime_tip);

        lb_lastSyncTime_value = new QLabel(page_main);
        lb_lastSyncTime_value->setObjectName(QString::fromUtf8("lb_lastSyncTime_value"));

        horizontalLayout_2->addWidget(lb_lastSyncTime_value);

        btn_remoteSync = new QPushButton(page_main);
        btn_remoteSync->setObjectName(QString::fromUtf8("btn_remoteSync"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/sync.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_remoteSync->setIcon(icon7);

        horizontalLayout_2->addWidget(btn_remoteSync);

        btn_newArchive = new QPushButton(page_main);
        btn_newArchive->setObjectName(QString::fromUtf8("btn_newArchive"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/add.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_newArchive->setIcon(icon8);

        horizontalLayout_2->addWidget(btn_newArchive);


        verticalLayout_3->addLayout(horizontalLayout_2);

        table_resultShow = new QTableWidget(page_main);
        if (table_resultShow->columnCount() < 9)
            table_resultShow->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_resultShow->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_resultShow->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_resultShow->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_resultShow->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_resultShow->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_resultShow->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_resultShow->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_resultShow->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_resultShow->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        table_resultShow->setObjectName(QString::fromUtf8("table_resultShow"));
        table_resultShow->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_resultShow->setTabKeyNavigation(false);
        table_resultShow->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_resultShow->horizontalHeader()->setDefaultSectionSize(80);
        table_resultShow->horizontalHeader()->setHighlightSections(false);
        table_resultShow->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(table_resultShow);

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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 444, 60));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        layout_settingPageOptions_1 = new QHBoxLayout();
        layout_settingPageOptions_1->setSpacing(6);
        layout_settingPageOptions_1->setObjectName(QString::fromUtf8("layout_settingPageOptions_1"));
        lb_windowCLoseAction = new QLabel(scrollAreaWidgetContents);
        lb_windowCLoseAction->setObjectName(QString::fromUtf8("lb_windowCLoseAction"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lb_windowCLoseAction->sizePolicy().hasHeightForWidth());
        lb_windowCLoseAction->setSizePolicy(sizePolicy2);

        layout_settingPageOptions_1->addWidget(lb_windowCLoseAction);

        combo_windowCloseAction = new QComboBox(scrollAreaWidgetContents);
        combo_windowCloseAction->addItem(QString());
        combo_windowCloseAction->addItem(QString());
        combo_windowCloseAction->setObjectName(QString::fromUtf8("combo_windowCloseAction"));
        sizePolicy1.setHeightForWidth(combo_windowCloseAction->sizePolicy().hasHeightForWidth());
        combo_windowCloseAction->setSizePolicy(sizePolicy1);

        layout_settingPageOptions_1->addWidget(combo_windowCloseAction);

        check_hideMainWindowWhenStart = new QCheckBox(scrollAreaWidgetContents);
        check_hideMainWindowWhenStart->setObjectName(QString::fromUtf8("check_hideMainWindowWhenStart"));
        check_hideMainWindowWhenStart->setLayoutDirection(Qt::RightToLeft);

        layout_settingPageOptions_1->addWidget(check_hideMainWindowWhenStart);

        check_showSystemMessageWhenStart = new QCheckBox(scrollAreaWidgetContents);
        check_showSystemMessageWhenStart->setObjectName(QString::fromUtf8("check_showSystemMessageWhenStart"));
        check_showSystemMessageWhenStart->setLayoutDirection(Qt::RightToLeft);

        layout_settingPageOptions_1->addWidget(check_showSystemMessageWhenStart);


        verticalLayout_4->addLayout(layout_settingPageOptions_1);

        layout_settingPageOptions_2 = new QHBoxLayout();
        layout_settingPageOptions_2->setSpacing(6);
        layout_settingPageOptions_2->setObjectName(QString::fromUtf8("layout_settingPageOptions_2"));
        lb_clipboardWriteContent = new QLabel(scrollAreaWidgetContents);
        lb_clipboardWriteContent->setObjectName(QString::fromUtf8("lb_clipboardWriteContent"));

        layout_settingPageOptions_2->addWidget(lb_clipboardWriteContent);

        combo_clipboardWriteContent = new QComboBox(scrollAreaWidgetContents);
        combo_clipboardWriteContent->addItem(QString());
        combo_clipboardWriteContent->addItem(QString());
        combo_clipboardWriteContent->addItem(QString());
        combo_clipboardWriteContent->setObjectName(QString::fromUtf8("combo_clipboardWriteContent"));

        layout_settingPageOptions_2->addWidget(combo_clipboardWriteContent);

        lb_clipboardWriteMode = new QLabel(scrollAreaWidgetContents);
        lb_clipboardWriteMode->setObjectName(QString::fromUtf8("lb_clipboardWriteMode"));

        layout_settingPageOptions_2->addWidget(lb_clipboardWriteMode);

        combo_clipboardWriteMode = new QComboBox(scrollAreaWidgetContents);
        combo_clipboardWriteMode->addItem(QString());
        combo_clipboardWriteMode->addItem(QString());
        combo_clipboardWriteMode->setObjectName(QString::fromUtf8("combo_clipboardWriteMode"));

        layout_settingPageOptions_2->addWidget(combo_clipboardWriteMode);

        tbtn_clipboardWriteHelp = new QToolButton(scrollAreaWidgetContents);
        tbtn_clipboardWriteHelp->setObjectName(QString::fromUtf8("tbtn_clipboardWriteHelp"));
        tbtn_clipboardWriteHelp->setToolTipDuration(60000);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/help.svg"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_clipboardWriteHelp->setIcon(icon9);

        layout_settingPageOptions_2->addWidget(tbtn_clipboardWriteHelp);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_settingPageOptions_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(layout_settingPageOptions_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        scroll_settingOptionsContainer->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scroll_settingOptionsContainer);

        layout_settingPageButtonBox = new QHBoxLayout();
        layout_settingPageButtonBox->setSpacing(6);
        layout_settingPageButtonBox->setObjectName(QString::fromUtf8("layout_settingPageButtonBox"));
        hs_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_settingPageButtonBox->addItem(hs_1);

        btn_settingReject = new QPushButton(page_setting);
        btn_settingReject->setObjectName(QString::fromUtf8("btn_settingReject"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_settingReject->setIcon(icon10);

        layout_settingPageButtonBox->addWidget(btn_settingReject);

        btn_settingConfirm = new QPushButton(page_setting);
        btn_settingConfirm->setObjectName(QString::fromUtf8("btn_settingConfirm"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icon/save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_settingConfirm->setIcon(icon11);

        layout_settingPageButtonBox->addWidget(btn_settingConfirm);

        btn_settingApply = new QPushButton(page_setting);
        btn_settingApply->setObjectName(QString::fromUtf8("btn_settingApply"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icon/done.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_settingApply->setIcon(icon12);

        layout_settingPageButtonBox->addWidget(btn_settingApply);


        verticalLayout_2->addLayout(layout_settingPageButtonBox);

        pages->addWidget(page_setting);

        verticalLayout->addWidget(pages);

        AccountAssistantClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AccountAssistantClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menu_option = new QMenu(menuBar);
        menu_option->setObjectName(QString::fromUtf8("menu_option"));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_safe = new QMenu(menuBar);
        menu_safe->setObjectName(QString::fromUtf8("menu_safe"));
        AccountAssistantClass->setMenuBar(menuBar);

        menuBar->addAction(menu_option->menuAction());
        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_safe->menuAction());
        menu_option->addAction(action_option_setting);
        menu_option->addAction(action_option_accountGroupSetting);
        menu_option->addSeparator();
        menu_option->addAction(action_option_quit);
        menu_file->addAction(action_file_import);
        menu_file->addAction(action_file_export);
        menu_safe->addAction(action_security_setting);

        retranslateUi(AccountAssistantClass);

        pages->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AccountAssistantClass);
    } // setupUi

    void retranslateUi(QMainWindow *AccountAssistantClass)
    {
        AccountAssistantClass->setWindowTitle(QCoreApplication::translate("AccountAssistantClass", "AccountAssistant", nullptr));
        action_option_setting->setText(QCoreApplication::translate("AccountAssistantClass", "\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        action_option_setting->setToolTip(QCoreApplication::translate("AccountAssistantClass", "\350\207\252\345\256\232\344\271\211\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        action_option_quit->setText(QCoreApplication::translate("AccountAssistantClass", "\351\200\200\345\207\272", nullptr));
        action_file_import->setText(QCoreApplication::translate("AccountAssistantClass", "\345\257\274\345\205\245\346\225\260\346\215\256", nullptr));
        action_file_export->setText(QCoreApplication::translate("AccountAssistantClass", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        action_security_setting->setText(QCoreApplication::translate("AccountAssistantClass", "\345\256\211\345\205\250\350\256\276\347\275\256", nullptr));
        action_option_accountGroupSetting->setText(QCoreApplication::translate("AccountAssistantClass", "\345\210\206\347\273\204\347\256\241\347\220\206", nullptr));
        lb_searchAccount->setText(QCoreApplication::translate("AccountAssistantClass", "\350\264\246\346\210\267\346\243\200\347\264\242", nullptr));
        combo_searchRule->setItemText(0, QCoreApplication::translate("AccountAssistantClass", "\346\243\200\347\264\242\345\271\266\350\276\223\345\207\272\345\205\250\351\203\250", nullptr));
        combo_searchRule->setItemText(1, QCoreApplication::translate("AccountAssistantClass", "\344\276\235\346\215\256\350\207\252\345\256\232\344\271\211\345\220\215\347\247\260", nullptr));
        combo_searchRule->setItemText(2, QCoreApplication::translate("AccountAssistantClass", "\344\276\235\346\215\256\347\224\250\346\210\267\345\220\215", nullptr));
        combo_searchRule->setItemText(3, QCoreApplication::translate("AccountAssistantClass", "\344\276\235\346\215\256\350\264\246\346\210\267\345\210\206\347\273\204", nullptr));

        btn_doSearch->setText(QCoreApplication::translate("AccountAssistantClass", "\346\243\200\347\264\242", nullptr));
        lb_resultCount_tip->setText(QCoreApplication::translate("AccountAssistantClass", "\347\273\223\346\236\234\346\225\260\351\207\217:", nullptr));
        lb_resultCount_value->setText(QCoreApplication::translate("AccountAssistantClass", "0", nullptr));
        lb_lastSyncTime_tip->setText(QCoreApplication::translate("AccountAssistantClass", "\344\270\212\346\254\241\345\220\214\346\255\245\346\227\266\351\227\264:", nullptr));
        lb_lastSyncTime_value->setText(QCoreApplication::translate("AccountAssistantClass", "2023-10-23 12:52:00", nullptr));
        btn_remoteSync->setText(QCoreApplication::translate("AccountAssistantClass", "\350\277\234\347\250\213\345\220\214\346\255\245", nullptr));
        btn_newArchive->setText(QCoreApplication::translate("AccountAssistantClass", "\346\226\260\345\273\272\345\255\230\346\241\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_resultShow->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AccountAssistantClass", "\350\207\252\345\256\232\344\271\211\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_resultShow->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AccountAssistantClass", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_resultShow->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AccountAssistantClass", "\345\257\206\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_resultShow->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AccountAssistantClass", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_resultShow->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AccountAssistantClass", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_resultShow->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AccountAssistantClass", "\345\210\206\347\273\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_resultShow->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AccountAssistantClass", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_resultShow->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("AccountAssistantClass", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table_resultShow->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("AccountAssistantClass", "id", nullptr));
        lb_windowCLoseAction->setText(QCoreApplication::translate("AccountAssistantClass", "\345\205\263\351\227\255\346\214\211\351\222\256\350\241\214\344\270\272", nullptr));
        combo_windowCloseAction->setItemText(0, QCoreApplication::translate("AccountAssistantClass", "\346\234\200\345\260\217\345\214\226", nullptr));
        combo_windowCloseAction->setItemText(1, QCoreApplication::translate("AccountAssistantClass", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));

        check_hideMainWindowWhenStart->setText(QCoreApplication::translate("AccountAssistantClass", "\345\220\257\345\212\250\346\227\266\351\232\220\350\227\217\344\270\273\347\252\227\345\217\243", nullptr));
        check_showSystemMessageWhenStart->setText(QCoreApplication::translate("AccountAssistantClass", "\345\220\257\345\212\250\346\227\266\346\230\276\347\244\272\347\263\273\347\273\237\346\217\220\347\244\272\346\266\210\346\201\257", nullptr));
        lb_clipboardWriteContent->setText(QCoreApplication::translate("AccountAssistantClass", "\345\244\215\345\210\266\350\264\246\346\210\267\346\227\266\345\220\221\345\211\252\345\210\207\346\235\277\345\206\205\345\206\231\345\205\245\347\232\204\345\206\205\345\256\271", nullptr));
        combo_clipboardWriteContent->setItemText(0, QCoreApplication::translate("AccountAssistantClass", "\347\224\250\346\210\267\345\220\215", nullptr));
        combo_clipboardWriteContent->setItemText(1, QCoreApplication::translate("AccountAssistantClass", "\345\257\206\347\240\201", nullptr));
        combo_clipboardWriteContent->setItemText(2, QCoreApplication::translate("AccountAssistantClass", "\345\205\250\351\203\250", nullptr));

        lb_clipboardWriteMode->setText(QCoreApplication::translate("AccountAssistantClass", "\345\206\231\345\205\245\346\250\241\345\274\217", nullptr));
        combo_clipboardWriteMode->setItemText(0, QCoreApplication::translate("AccountAssistantClass", "\345\220\210\345\271\266\345\220\216\345\206\231\345\205\245", nullptr));
        combo_clipboardWriteMode->setItemText(1, QCoreApplication::translate("AccountAssistantClass", "\347\233\221\345\220\254\346\250\241\345\274\217\345\206\231\345\205\245", nullptr));

#if QT_CONFIG(tooltip)
        tbtn_clipboardWriteHelp->setToolTip(QCoreApplication::translate("AccountAssistantClass", "<html><head/><body><p>\345\275\223\345\206\231\345\205\245\345\206\205\345\256\271\344\270\272\345\205\250\351\203\250\346\227\266\346\217\220\344\276\233\344\270\244\347\247\215\345\206\231\345\205\245\346\250\241\345\274\217:</p><p>\342\221\240 \345\220\210\345\271\266\345\220\216\345\206\231\345\205\245:</p><p>\350\257\245\346\250\241\345\274\217\344\270\213\345\244\215\345\210\266\350\264\246\346\210\267\346\227\266\344\274\232\345\260\206\347\224\250\346\210\267\345\220\215\344\270\216\345\257\206\347\240\201\347\224\250\347\251\272\346\240\274\350\277\236\346\216\245\345\220\216\344\270\200\346\254\241\346\200\247\345\206\231\345\205\245\345\211\252\345\210\207\346\235\277</p><p>\342\221\241 \347\233\221\345\220\254\346\250\241\345\274\217\345\206\231\345\205\245:</p><p>\350\257\245\346\250\241\345\274\217\344\270\213\345\244\215\345\210\266\350\264\246\346\210\267\346\227\266\344\274\232\351\246\226\345\205\210\345\260\206\347\224\250\346\210\267\345\220\215\345\206\231\345\205\245\345\211\252\345\210\207"
                        "\346\235\277, \345\220\214\346\227\266\347\233\221\345\220\254&quot;Ctrl + V&quot;\345\277\253\346\215\267\351\224\256,</p><p>\345\275\223\346\214\211\344\270\213\346\255\244\345\277\253\346\215\267\351\224\256\345\220\216\350\207\252\345\212\250\345\260\206\345\257\206\347\240\201\345\206\231\345\205\245\345\211\252\345\210\207\346\235\277</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbtn_clipboardWriteHelp->setText(QCoreApplication::translate("AccountAssistantClass", "...", nullptr));
        btn_settingReject->setText(QCoreApplication::translate("AccountAssistantClass", "\345\217\226\346\266\210", nullptr));
        btn_settingConfirm->setText(QCoreApplication::translate("AccountAssistantClass", "\347\241\256\350\256\244", nullptr));
        btn_settingApply->setText(QCoreApplication::translate("AccountAssistantClass", "\345\272\224\347\224\250", nullptr));
        menu_option->setTitle(QCoreApplication::translate("AccountAssistantClass", "\351\200\211\351\241\271", nullptr));
        menu_file->setTitle(QCoreApplication::translate("AccountAssistantClass", "\346\226\207\344\273\266", nullptr));
        menu_safe->setTitle(QCoreApplication::translate("AccountAssistantClass", "\345\256\211\345\205\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountAssistantClass: public Ui_AccountAssistantClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTASSISTANT_H
