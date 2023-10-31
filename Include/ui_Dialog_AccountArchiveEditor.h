/********************************************************************************
** Form generated from reading UI file 'Dialog_AccountArchiveEditor.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ACCOUNTARCHIVEEDITOR_H
#define UI_DIALOG_ACCOUNTARCHIVEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_AccountArchiveEditor
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *layout_noEncyData;
    QLabel *lb_customName;
    QLineEdit *ledit_customName;
    QLabel *lb_type;
    QHBoxLayout *layout_type;
    QSpacerItem *hs_type;
    QComboBox *combo_type;
    QPushButton *btn_typeEdit;
    QLabel *lb_createTime;
    QLabel *lb_updateTime;
    QLabel *lb_createTime_value;
    QLabel *lb_updateTime_value;
    QFrame *line;
    QHBoxLayout *layout_tip;
    QLabel *lb_tip;
    QSpacerItem *hs_tip;
    QPushButton *btn_showEncyData;
    QFormLayout *layout_encyData;
    QLabel *lb_comment;
    QLineEdit *ledit_comment;
    QLabel *lb_username;
    QHBoxLayout *layout_UP;
    QLineEdit *ledit_username;
    QLabel *lb_password;
    QLineEdit *ledit_password;
    QToolButton *tbtn_showUP;
    QToolButton *tbtn_copyUP;
    QLabel *lb_nickname;
    QHBoxLayout *layout_NU;
    QLineEdit *ledit_nickname;
    QLabel *lb_uid;
    QLineEdit *ledit_uid;
    QLabel *lb_phone;
    QHBoxLayout *layout_PE;
    QLineEdit *ledit_phone;
    QLabel *lb_email;
    QLineEdit *ledit_email;
    QLabel *lb_note;
    QTextEdit *tedit_note;
    QHBoxLayout *layout_controlBtn;
    QLabel *lb_state;
    QLabel *lb_checkState;
    QSpacerItem *hs_controlBtn;
    QPushButton *btn_reject;
    QPushButton *btn_check;
    QPushButton *btn_confirm;
    QPushButton *btn_save;
    QPushButton *btn_edit;

    void setupUi(QDialog *Dialog_AccountArchiveEditor)
    {
        if (Dialog_AccountArchiveEditor->objectName().isEmpty())
            Dialog_AccountArchiveEditor->setObjectName(QString::fromUtf8("Dialog_AccountArchiveEditor"));
        Dialog_AccountArchiveEditor->resize(650, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog_AccountArchiveEditor->sizePolicy().hasHeightForWidth());
        Dialog_AccountArchiveEditor->setSizePolicy(sizePolicy);
        Dialog_AccountArchiveEditor->setMinimumSize(QSize(650, 400));
        Dialog_AccountArchiveEditor->setMaximumSize(QSize(650, 400));
        verticalLayout = new QVBoxLayout(Dialog_AccountArchiveEditor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        layout_noEncyData = new QFormLayout();
        layout_noEncyData->setObjectName(QString::fromUtf8("layout_noEncyData"));
        layout_noEncyData->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lb_customName = new QLabel(Dialog_AccountArchiveEditor);
        lb_customName->setObjectName(QString::fromUtf8("lb_customName"));

        layout_noEncyData->setWidget(0, QFormLayout::LabelRole, lb_customName);

        ledit_customName = new QLineEdit(Dialog_AccountArchiveEditor);
        ledit_customName->setObjectName(QString::fromUtf8("ledit_customName"));

        layout_noEncyData->setWidget(0, QFormLayout::FieldRole, ledit_customName);

        lb_type = new QLabel(Dialog_AccountArchiveEditor);
        lb_type->setObjectName(QString::fromUtf8("lb_type"));

        layout_noEncyData->setWidget(1, QFormLayout::LabelRole, lb_type);

        layout_type = new QHBoxLayout();
        layout_type->setObjectName(QString::fromUtf8("layout_type"));
        hs_type = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_type->addItem(hs_type);

        combo_type = new QComboBox(Dialog_AccountArchiveEditor);
        combo_type->addItem(QString());
        combo_type->setObjectName(QString::fromUtf8("combo_type"));

        layout_type->addWidget(combo_type);

        btn_typeEdit = new QPushButton(Dialog_AccountArchiveEditor);
        btn_typeEdit->setObjectName(QString::fromUtf8("btn_typeEdit"));
        btn_typeEdit->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/remove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_typeEdit->setIcon(icon);

        layout_type->addWidget(btn_typeEdit);


        layout_noEncyData->setLayout(1, QFormLayout::FieldRole, layout_type);

        lb_createTime = new QLabel(Dialog_AccountArchiveEditor);
        lb_createTime->setObjectName(QString::fromUtf8("lb_createTime"));

        layout_noEncyData->setWidget(2, QFormLayout::LabelRole, lb_createTime);

        lb_updateTime = new QLabel(Dialog_AccountArchiveEditor);
        lb_updateTime->setObjectName(QString::fromUtf8("lb_updateTime"));

        layout_noEncyData->setWidget(3, QFormLayout::LabelRole, lb_updateTime);

        lb_createTime_value = new QLabel(Dialog_AccountArchiveEditor);
        lb_createTime_value->setObjectName(QString::fromUtf8("lb_createTime_value"));
        lb_createTime_value->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);"));

        layout_noEncyData->setWidget(2, QFormLayout::FieldRole, lb_createTime_value);

        lb_updateTime_value = new QLabel(Dialog_AccountArchiveEditor);
        lb_updateTime_value->setObjectName(QString::fromUtf8("lb_updateTime_value"));
        lb_updateTime_value->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);"));

        layout_noEncyData->setWidget(3, QFormLayout::FieldRole, lb_updateTime_value);


        verticalLayout->addLayout(layout_noEncyData);

        line = new QFrame(Dialog_AccountArchiveEditor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        layout_tip = new QHBoxLayout();
        layout_tip->setObjectName(QString::fromUtf8("layout_tip"));
        lb_tip = new QLabel(Dialog_AccountArchiveEditor);
        lb_tip->setObjectName(QString::fromUtf8("lb_tip"));

        layout_tip->addWidget(lb_tip);

        hs_tip = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_tip->addItem(hs_tip);

        btn_showEncyData = new QPushButton(Dialog_AccountArchiveEditor);
        btn_showEncyData->setObjectName(QString::fromUtf8("btn_showEncyData"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/visibility_off.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_showEncyData->setIcon(icon1);

        layout_tip->addWidget(btn_showEncyData);


        verticalLayout->addLayout(layout_tip);

        layout_encyData = new QFormLayout();
        layout_encyData->setObjectName(QString::fromUtf8("layout_encyData"));
        layout_encyData->setLabelAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        lb_comment = new QLabel(Dialog_AccountArchiveEditor);
        lb_comment->setObjectName(QString::fromUtf8("lb_comment"));

        layout_encyData->setWidget(0, QFormLayout::LabelRole, lb_comment);

        ledit_comment = new QLineEdit(Dialog_AccountArchiveEditor);
        ledit_comment->setObjectName(QString::fromUtf8("ledit_comment"));

        layout_encyData->setWidget(0, QFormLayout::FieldRole, ledit_comment);

        lb_username = new QLabel(Dialog_AccountArchiveEditor);
        lb_username->setObjectName(QString::fromUtf8("lb_username"));

        layout_encyData->setWidget(1, QFormLayout::LabelRole, lb_username);

        layout_UP = new QHBoxLayout();
        layout_UP->setObjectName(QString::fromUtf8("layout_UP"));
        ledit_username = new QLineEdit(Dialog_AccountArchiveEditor);
        ledit_username->setObjectName(QString::fromUtf8("ledit_username"));
        sizePolicy.setHeightForWidth(ledit_username->sizePolicy().hasHeightForWidth());
        ledit_username->setSizePolicy(sizePolicy);
        ledit_username->setMinimumSize(QSize(240, 0));
        ledit_username->setMaximumSize(QSize(240, 16777215));
        ledit_username->setEchoMode(QLineEdit::Password);
        ledit_username->setReadOnly(true);

        layout_UP->addWidget(ledit_username);

        lb_password = new QLabel(Dialog_AccountArchiveEditor);
        lb_password->setObjectName(QString::fromUtf8("lb_password"));
        sizePolicy.setHeightForWidth(lb_password->sizePolicy().hasHeightForWidth());
        lb_password->setSizePolicy(sizePolicy);
        lb_password->setMinimumSize(QSize(30, 0));
        lb_password->setMaximumSize(QSize(30, 16777215));

        layout_UP->addWidget(lb_password);

        ledit_password = new QLineEdit(Dialog_AccountArchiveEditor);
        ledit_password->setObjectName(QString::fromUtf8("ledit_password"));
        ledit_password->setEchoMode(QLineEdit::Password);
        ledit_password->setReadOnly(true);

        layout_UP->addWidget(ledit_password);

        tbtn_showUP = new QToolButton(Dialog_AccountArchiveEditor);
        tbtn_showUP->setObjectName(QString::fromUtf8("tbtn_showUP"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/visibility.svg"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_showUP->setIcon(icon2);

        layout_UP->addWidget(tbtn_showUP);

        tbtn_copyUP = new QToolButton(Dialog_AccountArchiveEditor);
        tbtn_copyUP->setObjectName(QString::fromUtf8("tbtn_copyUP"));
        tbtn_copyUP->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/copy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_copyUP->setIcon(icon3);

        layout_UP->addWidget(tbtn_copyUP);


        layout_encyData->setLayout(1, QFormLayout::FieldRole, layout_UP);

        lb_nickname = new QLabel(Dialog_AccountArchiveEditor);
        lb_nickname->setObjectName(QString::fromUtf8("lb_nickname"));

        layout_encyData->setWidget(2, QFormLayout::LabelRole, lb_nickname);

        layout_NU = new QHBoxLayout();
        layout_NU->setObjectName(QString::fromUtf8("layout_NU"));
        ledit_nickname = new QLineEdit(Dialog_AccountArchiveEditor);
        ledit_nickname->setObjectName(QString::fromUtf8("ledit_nickname"));
        sizePolicy.setHeightForWidth(ledit_nickname->sizePolicy().hasHeightForWidth());
        ledit_nickname->setSizePolicy(sizePolicy);
        ledit_nickname->setMinimumSize(QSize(240, 0));
        ledit_nickname->setMaximumSize(QSize(240, 16777215));

        layout_NU->addWidget(ledit_nickname);

        lb_uid = new QLabel(Dialog_AccountArchiveEditor);
        lb_uid->setObjectName(QString::fromUtf8("lb_uid"));
        sizePolicy.setHeightForWidth(lb_uid->sizePolicy().hasHeightForWidth());
        lb_uid->setSizePolicy(sizePolicy);
        lb_uid->setMinimumSize(QSize(30, 0));
        lb_uid->setMaximumSize(QSize(30, 16777215));

        layout_NU->addWidget(lb_uid);

        ledit_uid = new QLineEdit(Dialog_AccountArchiveEditor);
        ledit_uid->setObjectName(QString::fromUtf8("ledit_uid"));

        layout_NU->addWidget(ledit_uid);


        layout_encyData->setLayout(2, QFormLayout::FieldRole, layout_NU);

        lb_phone = new QLabel(Dialog_AccountArchiveEditor);
        lb_phone->setObjectName(QString::fromUtf8("lb_phone"));

        layout_encyData->setWidget(3, QFormLayout::LabelRole, lb_phone);

        layout_PE = new QHBoxLayout();
        layout_PE->setObjectName(QString::fromUtf8("layout_PE"));
        ledit_phone = new QLineEdit(Dialog_AccountArchiveEditor);
        ledit_phone->setObjectName(QString::fromUtf8("ledit_phone"));
        sizePolicy.setHeightForWidth(ledit_phone->sizePolicy().hasHeightForWidth());
        ledit_phone->setSizePolicy(sizePolicy);
        ledit_phone->setMinimumSize(QSize(240, 0));
        ledit_phone->setMaximumSize(QSize(240, 16777215));

        layout_PE->addWidget(ledit_phone);

        lb_email = new QLabel(Dialog_AccountArchiveEditor);
        lb_email->setObjectName(QString::fromUtf8("lb_email"));
        sizePolicy.setHeightForWidth(lb_email->sizePolicy().hasHeightForWidth());
        lb_email->setSizePolicy(sizePolicy);
        lb_email->setMinimumSize(QSize(30, 0));
        lb_email->setMaximumSize(QSize(30, 16777215));

        layout_PE->addWidget(lb_email);

        ledit_email = new QLineEdit(Dialog_AccountArchiveEditor);
        ledit_email->setObjectName(QString::fromUtf8("ledit_email"));

        layout_PE->addWidget(ledit_email);


        layout_encyData->setLayout(3, QFormLayout::FieldRole, layout_PE);

        lb_note = new QLabel(Dialog_AccountArchiveEditor);
        lb_note->setObjectName(QString::fromUtf8("lb_note"));

        layout_encyData->setWidget(4, QFormLayout::LabelRole, lb_note);

        tedit_note = new QTextEdit(Dialog_AccountArchiveEditor);
        tedit_note->setObjectName(QString::fromUtf8("tedit_note"));

        layout_encyData->setWidget(4, QFormLayout::FieldRole, tedit_note);


        verticalLayout->addLayout(layout_encyData);

        layout_controlBtn = new QHBoxLayout();
        layout_controlBtn->setObjectName(QString::fromUtf8("layout_controlBtn"));
        lb_state = new QLabel(Dialog_AccountArchiveEditor);
        lb_state->setObjectName(QString::fromUtf8("lb_state"));

        layout_controlBtn->addWidget(lb_state);

        lb_checkState = new QLabel(Dialog_AccountArchiveEditor);
        lb_checkState->setObjectName(QString::fromUtf8("lb_checkState"));

        layout_controlBtn->addWidget(lb_checkState);

        hs_controlBtn = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_controlBtn->addItem(hs_controlBtn);

        btn_reject = new QPushButton(Dialog_AccountArchiveEditor);
        btn_reject->setObjectName(QString::fromUtf8("btn_reject"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_reject->setIcon(icon4);

        layout_controlBtn->addWidget(btn_reject);

        btn_check = new QPushButton(Dialog_AccountArchiveEditor);
        btn_check->setObjectName(QString::fromUtf8("btn_check"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/search.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_check->setIcon(icon5);

        layout_controlBtn->addWidget(btn_check);

        btn_confirm = new QPushButton(Dialog_AccountArchiveEditor);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/done.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon6);

        layout_controlBtn->addWidget(btn_confirm);

        btn_save = new QPushButton(Dialog_AccountArchiveEditor);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_save->setIcon(icon7);

        layout_controlBtn->addWidget(btn_save);

        btn_edit = new QPushButton(Dialog_AccountArchiveEditor);
        btn_edit->setObjectName(QString::fromUtf8("btn_edit"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/edit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_edit->setIcon(icon8);

        layout_controlBtn->addWidget(btn_edit);


        verticalLayout->addLayout(layout_controlBtn);


        retranslateUi(Dialog_AccountArchiveEditor);

        QMetaObject::connectSlotsByName(Dialog_AccountArchiveEditor);
    } // setupUi

    void retranslateUi(QDialog *Dialog_AccountArchiveEditor)
    {
        Dialog_AccountArchiveEditor->setWindowTitle(QCoreApplication::translate("Dialog_AccountArchiveEditor", "Dialog", nullptr));
        lb_customName->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\350\207\252\345\256\232\344\271\211\346\220\234\347\264\242\346\240\207\347\255\276:", nullptr));
#if QT_CONFIG(tooltip)
        ledit_customName->setToolTip(QCoreApplication::translate("Dialog_AccountArchiveEditor", "<html><head/><body><p>\342\221\240\346\220\234\347\264\242\346\240\207\347\255\276\347\224\250\344\272\216\345\277\253\351\200\237\346\220\234\347\264\242\345\210\260\350\257\245\350\264\246\346\210\267\345\255\230\346\241\243</p><p>\342\221\241\351\234\200\350\246\201\350\276\223\345\205\245\350\207\263\345\260\221\344\270\200\344\270\252\346\220\234\347\264\242\346\240\207\347\255\276\344\273\245\344\276\233\346\220\234\347\264\242,\350\207\263\345\244\232\350\256\276\347\275\256\344\270\211\344\270\252,\345\244\232\344\270\252\346\240\207\347\255\276\344\271\213\351\227\264\344\275\277\347\224\250\345\210\206\345\217\267&quot;;&quot;\345\210\206\351\232\224</p><p>\342\221\242\346\240\207\347\255\276\344\273\205\346\224\257\346\214\201\344\270\255\346\226\207,\350\213\261\346\226\207\345\222\214\346\225\260\345\255\227</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ledit_customName->setPlaceholderText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\350\276\223\345\205\245\350\207\263\345\260\221\344\270\200\344\270\252\346\220\234\347\264\242\346\240\207\347\255\276,\345\244\232\344\270\252\344\271\213\351\227\264\344\275\277\347\224\250\345\210\206\345\217\267\";\"\345\210\206\351\232\224,\350\207\263\345\244\232\350\256\276\347\275\256\344\270\211\344\270\252", nullptr));
        lb_type->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\350\264\246\346\210\267\347\261\273\345\236\213:", nullptr));
        combo_type->setItemText(0, QCoreApplication::translate("Dialog_AccountArchiveEditor", "\351\273\230\350\256\244\347\261\273\345\236\213", nullptr));

        btn_typeEdit->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\347\247\273\351\231\244", nullptr));
        lb_createTime->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\345\210\233\345\273\272\346\227\266\351\227\264:", nullptr));
        lb_updateTime->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\346\233\264\346\226\260\346\227\266\351\227\264:", nullptr));
        lb_createTime_value->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "2023-10-30 11:20:00", nullptr));
        lb_updateTime_value->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "2023-10-30 11:20:00", nullptr));
        lb_tip->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\344\273\245\344\270\213\344\270\272\345\212\240\345\257\206\344\277\241\346\201\257", nullptr));
        btn_showEncyData->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\351\232\220\350\227\217\350\257\246\346\203\205", nullptr));
        lb_comment->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\345\255\230\346\241\243\346\263\250\351\207\212:", nullptr));
        ledit_comment->setPlaceholderText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\350\257\267\350\276\223\345\205\245", nullptr));
        lb_username->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\347\224\250\346\210\267\345\220\215:", nullptr));
        lb_password->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\345\257\206\347\240\201:", nullptr));
        tbtn_showUP->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "...", nullptr));
        tbtn_copyUP->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "...", nullptr));
        lb_nickname->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\346\230\265\347\247\260:", nullptr));
        ledit_nickname->setPlaceholderText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\350\257\267\350\276\223\345\205\245", nullptr));
        lb_uid->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "UID:", nullptr));
        ledit_uid->setPlaceholderText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\350\257\267\350\276\223\345\205\245", nullptr));
        lb_phone->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\346\211\213\346\234\272:", nullptr));
#if QT_CONFIG(tooltip)
        ledit_phone->setToolTip(QCoreApplication::translate("Dialog_AccountArchiveEditor", "<html><head/><body><p>\346\211\213\346\234\272\345\217\267\346\224\257\346\214\201\345\246\202\344\270\213\346\240\274\345\274\217:</p><p>\342\221\240\344\273\205\345\217\267\347\240\201: 123456789</p><p>\342\221\241\345\233\275\345\256\266\344\273\243\347\240\201+\345\217\267\347\240\201: +1 123456789</p><p>\342\221\242\345\214\272\345\217\267+\345\217\267\347\240\201: (10) 123456789</p><p>\342\221\243\345\233\275\345\256\266\344\273\243\347\240\201+\345\214\272\345\217\267+\345\217\267\347\240\201: +1 (1234) 56789012</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ledit_phone->setPlaceholderText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\350\257\267\350\276\223\345\205\245", nullptr));
        lb_email->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\351\202\256\347\256\261:", nullptr));
        ledit_email->setPlaceholderText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\350\257\267\350\276\223\345\205\245", nullptr));
        lb_note->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\347\254\224\350\256\260:", nullptr));
        lb_state->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\345\217\252\350\257\273\346\250\241\345\274\217", nullptr));
        lb_checkState->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\346\234\252\346\243\200\346\237\245", nullptr));
        btn_reject->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\345\205\263\351\227\255", nullptr));
        btn_check->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\346\243\200\346\237\245", nullptr));
        btn_confirm->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\347\241\256\350\256\244", nullptr));
        btn_save->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\344\277\235\345\255\230", nullptr));
        btn_edit->setText(QCoreApplication::translate("Dialog_AccountArchiveEditor", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_AccountArchiveEditor: public Ui_Dialog_AccountArchiveEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ACCOUNTARCHIVEEDITOR_H
