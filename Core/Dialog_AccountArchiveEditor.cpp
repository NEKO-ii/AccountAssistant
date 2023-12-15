#include "Dialog_AccountArchiveEditor.h"

#include "Tools.h"
#include "State.h"
#include "EnDecryption.h"
#include <format>
#include <QDateTime>
#include <QMessageBox>
#include <QTimer>
#include <QPointer>

Dialog_AccountArchiveEditor::Dialog_AccountArchiveEditor(QWidget* parent, unsigned int id)
    :QDialog(parent), _id(id), _openMode(OpenMode::CREATE), _isDefaultTypeLabelRemoved(false)
{
    _item = AccountItem();
    _ui.setupUi(this);
    _initWidgetState();
    _initData();
    _connect();
}

Dialog_AccountArchiveEditor::Dialog_AccountArchiveEditor(QWidget* parent, unsigned int id, const AccountItem& item)
    :QDialog(parent), _id(id), _openMode(OpenMode::UPDATE), _isDefaultTypeLabelRemoved(true)
{
    _item = AccountItem(item);
    _ui.setupUi(this);
    _initWidgetState();
    _initData();
    _connect();
}

Dialog_AccountArchiveEditor::~Dialog_AccountArchiveEditor() {}

void Dialog_AccountArchiveEditor::_connect(void)
{
    // 类型标签控制
    connect(_ui.combo_type, &QComboBox::currentIndexChanged, this, &Dialog_AccountArchiveEditor::_updateTypeControlBtn);
    connect(_ui.btn_typeEdit, &QPushButton::clicked, this, [this]
        {
            if (_currentTypeControlBtnAction == "remove")
            {
                _removeTypeLabel(_ui.combo_type->currentIndex());
                _updateTypeControlBtn();
            }
            else if (_currentTypeControlBtnAction == "create")
            {
                if (_openMode == OpenMode::CREATE && !_isDefaultTypeLabelRemoved)
                {
                    _removeTypeLabel(0);
                    _isDefaultTypeLabelRemoved = true;
                }
                _insertTypeLabel(Define::AccountType(_ui.combo_type->currentIndex()));
                _updateTypeControlBtn();
            }
        });
    // 加密信息展示切换
    connect(_ui.btn_showEncyData, &QPushButton::clicked, this, [this]
        {
            QPushButton* btn = _ui.btn_showEncyData;
            QIcon icon;
            if (_isEncyInfoHide)
            {
                icon.addFile(QString::fromUtf8(":/icon/visibility_off.svg"), QSize(), QIcon::Normal, QIcon::Off);
                btn->setText(tr("隐藏详情"));
                _ui.ledit_comment->setText(_item.comment);
                _ui.ledit_username->setText(_item.username);
                _ui.ledit_password->setText(_item.password);
                _ui.ledit_nickname->setText(_item.nickname);
                _ui.ledit_uid->setText(_item.uid);
                _ui.ledit_phone->setText(_item.phone);
                _ui.ledit_email->setText(_item.email);
                _ui.tedit_note->setPlainText(_item.note);
            }
            else
            {
                icon.addFile(QString::fromUtf8(":/icon/visibility.svg"), QSize(), QIcon::Normal, QIcon::Off);
                btn->setText(tr("显示详情"));
                _ui.ledit_comment->setText("[数据已加密并隐藏]");
                _ui.ledit_username->setText("Username");
                _ui.ledit_password->setText("Password");
                _ui.ledit_nickname->setText("[数据已加密并隐藏]");
                _ui.ledit_uid->setText("[数据已加密并隐藏]");
                _ui.ledit_phone->setText("[数据已加密并隐藏]");
                _ui.ledit_email->setText("[数据已加密并隐藏]");
                _ui.tedit_note->setPlainText("[数据已加密并隐藏]");
            }
            btn->setIcon(icon);
            _isEncyInfoHide = !_isEncyInfoHide;
        });
    // 编辑模式
    connect(_ui.btn_edit, &QPushButton::clicked, this, [this]
        {
            _switchEditMode();
            _updateTypeControlBtn();
            _ui.btn_save->hide();
            _ui.btn_edit->hide();
            _ui.btn_check->show();
            _ui.btn_confirm->show();
            if (_isEncyInfoHide) _ui.btn_showEncyData->click();
            _ui.btn_showEncyData->setEnabled(false);
            _ui.lb_checkState->setText(tr("未检查"));
            _ui.lb_checkState->setStyleSheet("color: rgb(0,0,0);");
        });
    // 确认按钮
    connect(_ui.btn_confirm, &QPushButton::clicked, this, [this]
        {
            if (!_check()) return;
            _updateDataItem();
            _switchEditMode();
            _updateTypeControlBtn();
            _ui.btn_save->show();
            _ui.btn_edit->show();
            _ui.btn_check->hide();
            _ui.btn_confirm->hide();
            _ui.btn_showEncyData->setEnabled(true);
            _ui.btn_showEncyData->click();
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            _ui.lb_updateTime_value->setText(currentTime);
            _ui.lb_updateTime_value->setStyleSheet("color: rgb(0,255,0);");
            // 使用QPointer传递给lambda函数,避免定时器未触发时关闭对话框导致的空指针问题
            QPointer<Dialog_AccountArchiveEditor> dlg = this;
            QTimer::singleShot(3000, [dlg]
                {
                    if (dlg != nullptr) dlg->_ui.lb_updateTime_value->setStyleSheet("color: rgb(85, 85, 255);");
                });
        });
    // 关闭按钮
    connect(_ui.btn_reject, &QPushButton::clicked, this, &Dialog_AccountArchiveEditor::reject);
    // 保存按钮
    connect(_ui.btn_save, &QPushButton::clicked, this, [this]
        {
            emit signal_save(_id, _item, _openMode);
            accept();
        });
    // 检查按钮
    connect(_ui.btn_check, &QPushButton::clicked, this, &Dialog_AccountArchiveEditor::_check);
    // 显示账号密码按钮
    connect(_ui.tbtn_showUP, &QToolButton::clicked, this, [this]
        {
            QLineEdit::EchoMode em = _ui.ledit_password->echoMode();
            QIcon icon;
            if (em == QLineEdit::EchoMode::Normal)
            {
                _ui.ledit_username->setEchoMode(QLineEdit::EchoMode::Password);
                _ui.ledit_password->setEchoMode(QLineEdit::EchoMode::Password);
                if (!_isOnEditMode) {
                    _ui.ledit_username->setText("Username");
                    _ui.ledit_password->setText("Password");
                }
                icon.addFile(QString::fromUtf8(":/icon/visibility.svg"), QSize(), QIcon::Normal, QIcon::Off);
                _ui.tbtn_showUP->setIcon(icon);
            }
            else if (em == QLineEdit::EchoMode::Password)
            {
                _ui.ledit_username->setEchoMode(QLineEdit::EchoMode::Normal);
                _ui.ledit_password->setEchoMode(QLineEdit::EchoMode::Normal);
                if (!_isOnEditMode) {
                    _ui.ledit_username->setText(_item.username);
                    _ui.ledit_password->setText(_item.password);
                }
                icon.addFile(QString::fromUtf8(":/icon/visibility_off.svg"), QSize(), QIcon::Normal, QIcon::Off);
                _ui.tbtn_showUP->setIcon(icon);
            }
        });
}

void Dialog_AccountArchiveEditor::_initWidgetState(void)
{
    //this->setAttribute(Qt::WA_DeleteOnClose);
    // 设置输入限制
    // 自定义搜索标签仅支持中英文,数字以及分隔符";"
    QRegularExpressionValidator* validator_customName = new QRegularExpressionValidator(QRegularExpression("[\u4E00-\u9FA5a-zA-Z;0-9]*"), _ui.ledit_customName);
    _ui.ledit_customName->setValidator(validator_customName);
    // 用户名与密码不允许输入空格和英文冒号":"
    QRegularExpressionValidator* validator_UP = new QRegularExpressionValidator(QRegularExpression("^[^: ]*$"), this);
    _ui.ledit_username->setValidator(validator_UP);
    _ui.ledit_password->setValidator(validator_UP);
    // 电话格式限制,国家代码,区号,号码任意排列组合(号码必填)
    QRegularExpressionValidator* validator_phone = new QRegularExpressionValidator(QRegularExpression("^(\\+\\d{1,3}\\s?)?(\\(\\d{1,4}\\)\\s?)?\\d{3,}$"), _ui.ledit_phone);
    _ui.ledit_phone->setValidator(validator_phone);
    // UID仅支持英文和数字
    QRegularExpressionValidator* validator_uid = new QRegularExpressionValidator(QRegularExpression("^[a-zA-Z0-9]*$"), _ui.ledit_uid);
    _ui.ledit_uid->setValidator(validator_uid);
    // 邮箱格式检查
    QRegularExpressionValidator* validator_email = new QRegularExpressionValidator(QRegularExpression("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"), _ui.ledit_email);
    _ui.ledit_email->setValidator(validator_email);
    // 默认,不允许使用英文冒号":"
    QRegularExpressionValidator* validator_def = new QRegularExpressionValidator(QRegularExpression("[^:]*"), this);
    _ui.ledit_comment->setValidator(validator_def);
    _ui.ledit_nickname->setValidator(validator_def);


    // 设置组件初始状态
    // 读取标签类型设置
    QComboBox* combo_type = _ui.combo_type;
    combo_type->clear();
    for (auto& item : Define::AccountTypeLabelTitle) combo_type->addItem(QString(item.second.c_str()));
    combo_type->setCurrentIndex(0);

    if (_openMode == OpenMode::CREATE)
    {
        this->setWindowTitle("新建账户存档");
        _isEncyInfoHide = false;
        _isOnEditMode = false;
        _switchEditMode();
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/visibility_off.svg"), QSize(), QIcon::Normal, QIcon::Off);
        _ui.btn_showEncyData->setIcon(icon);
        _ui.btn_showEncyData->setText(tr("隐藏详情"));
        _ui.btn_showEncyData->setEnabled(false);
        _ui.tbtn_copyUP->setEnabled(false);
        _ui.btn_edit->hide();
        _ui.btn_save->hide();
    }
    else
    {
        this->setWindowTitle(tr("账户存档详情"));
        _isEncyInfoHide = true;
        _isOnEditMode = true;
        _switchEditMode();
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/visibility.svg"), QSize(), QIcon::Normal, QIcon::Off);
        _ui.btn_showEncyData->setIcon(icon);
        _ui.btn_showEncyData->setText(tr("显示详情"));
        _ui.tbtn_copyUP->setEnabled(true);
        _ui.btn_check->hide();
        _ui.btn_confirm->hide();
    }
}

void Dialog_AccountArchiveEditor::_initData(void)
{
    if (_openMode == OpenMode::CREATE) {
        _insertTypeLabel(Define::AccountType::DEFAULT);
        _updateTypeControlBtn();
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        _ui.lb_createTime_value->setText(currentTime);
        _ui.lb_updateTime_value->setText(currentTime);
    }
    else if (_openMode == OpenMode::UPDATE)
    {
        _ui.ledit_customName->setText(_item.customName);
        for (auto& item : Tools::split(_item.type.toStdString(), ";")) _insertTypeLabel(Define::AccountType(std::stoi(item)));
        _updateTypeControlBtn();
        _ui.lb_createTime_value->setText(_item.createTime);
        _ui.lb_updateTime_value->setText(_item.updateTime);
        _ui.ledit_comment->setText("[数据已加密并隐藏]");
        _ui.ledit_username->setText("Username");
        _ui.ledit_password->setText("Password");
        _ui.ledit_nickname->setText("[数据已加密并隐藏]");
        _ui.ledit_uid->setText("[数据已加密并隐藏]");
        _ui.ledit_phone->setText("[数据已加密并隐藏]");
        _ui.ledit_email->setText("[数据已加密并隐藏]");
        _ui.tedit_note->setPlainText("[数据已加密并隐藏]");
    }
}

bool Dialog_AccountArchiveEditor::_check(void)
{
    QString msg;
    bool flag = true;
    QString temp = _ui.ledit_customName->text();
    if (temp.isEmpty() || Tools::split(temp.toStdString(), ";").size() > 3) { msg.append(tr("自定义搜索标签至少设置一个,至多设置三个\n")); flag = false; }
    if (!_ui.ledit_customName->hasAcceptableInput()) { msg.append(tr("自定义搜索标签格式有误\n")); flag = false; }
    if (!_ui.ledit_comment->hasAcceptableInput()) { msg.append(tr("存档注释格式有误: 不能包含英文冒号\n")); flag = false; }
    if (!_ui.ledit_username->hasAcceptableInput()) { msg.append(tr("用户名格式有误: 不能包含空格和英文冒号\n")); flag = false; }
    if (_ui.ledit_password->text().isEmpty()) { msg.append(tr("密码不能为空\n")); flag = false; }
    if (!_ui.ledit_password->hasAcceptableInput()) { msg.append(tr("密码格式有误: 不能包含空格和英文冒号\n")); flag = false; }
    if (!_ui.ledit_nickname->hasAcceptableInput()) { msg.append(tr("昵称格式有误: 不能包含英文冒号\n")); flag = false; }
    if (!_ui.ledit_uid->hasAcceptableInput()) { msg.append(tr("UID格式有误: 只能包含数字和英文字母\n")); flag = false; }
    if (!_ui.ledit_phone->hasAcceptableInput() && !_ui.ledit_phone->text().isEmpty()) { msg.append(tr("手机号格式有误: 支持特定格式\n")); flag = false; }
    if (!_ui.ledit_email->hasAcceptableInput() && !_ui.ledit_email->text().isEmpty()) { msg.append(tr("邮箱格式有误\n")); flag = false; }

    // 弹出提示消息
    if (flag)
    {
        _ui.lb_checkState->setText(tr("数据无误"));
        _ui.lb_checkState->setStyleSheet("color: rgb(0,255,0);");
    }
    else
    {
        QMessageBox(QMessageBox::Critical, "输入有误", msg, QMessageBox::Ok, nullptr, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint).exec();
        _ui.lb_checkState->setText(tr("数据有误"));
        _ui.lb_checkState->setStyleSheet("color: rgb(255,0,0);");
    }

    return flag;
}

void Dialog_AccountArchiveEditor::_updateDataItem(void)
{
    _item.customName = _ui.ledit_customName->text();
    std::string typestr = std::to_string(_typeGroup[0]);
    for (std::vector<int>::iterator i = ++_typeGroup.begin(); i != _typeGroup.end(); i++) typestr.append(std::format(";{}", *i));
    _item.type = QString(typestr.c_str());
    _item.createTime = _ui.lb_createTime_value->text();
    _item.updateTime = _ui.lb_updateTime_value->text();
    _item.comment = _ui.ledit_comment->text();
    _item.username = _ui.ledit_username->text();
    _item.password = _ui.ledit_password->text();
    _item.nickname = _ui.ledit_nickname->text();
    _item.uid = _ui.ledit_uid->text();
    _item.phone = _ui.ledit_phone->text();
    _item.email = _ui.ledit_email->text();
    _item.note = _ui.tedit_note->toPlainText();
}

void Dialog_AccountArchiveEditor::_updateTypeControlBtn(void)
{
    // 通过禁用操作按钮,保证标签组数量在1~_ACCOUNT_TYPE_GROUP_LIMIT之间
    int index = _ui.combo_type->currentIndex();
    int size = _typeGroup.size();
    bool isIndexExist = Tools::isInVector<int>(index, _typeGroup);
    if (!_isOnEditMode) _ui.btn_typeEdit->setEnabled(false);
    else if ((size <= 1 && isIndexExist) || (size >= _ACCOUNT_TYPE_GROUP_LIMIT && !isIndexExist)) _ui.btn_typeEdit->setEnabled(false);
    // 控制按钮锁定确保默认类型只能单独存在
    else if (index == (int)Define::AccountType::DEFAULT && !isIndexExist) _ui.btn_typeEdit->setEnabled(false);
    else _ui.btn_typeEdit->setEnabled(true);
    // 修改按钮文本以及图标
    QIcon icon;
    if (isIndexExist)
    {
        icon.addFile(QString::fromUtf8(":/icon/remove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        _ui.btn_typeEdit->setIcon(icon);
        _ui.btn_typeEdit->setText(tr("移除"));
        _currentTypeControlBtnAction = "remove";
    }
    else
    {
        icon.addFile(QString::fromUtf8(":/icon/add.svg"), QSize(), QIcon::Normal, QIcon::Off);
        _ui.btn_typeEdit->setIcon(icon);
        _ui.btn_typeEdit->setText(tr("添加"));
        _currentTypeControlBtnAction = "create";
    }
}

void Dialog_AccountArchiveEditor::_insertTypeLabel(const Define::AccountType& type)
{
    QString styleSheet = QString::fromUtf8(std::format(
        "background-color: {0};\n"
        "border: 1px;\n"
        "border-color: {0};\n"
        "border-radius: 5px;\n"
        "padding-left: 6px;\n"
        "padding-right: 6px;"
        , Define::AccountTypeLabelColor[type]));
    QLabel* label = new QLabel(Define::AccountTypeLabelTitle[type].c_str(), this);
    label->setObjectName(std::format("lb_type_{}", (int)type).c_str());
    label->setStyleSheet(styleSheet);
    _ui.layout_type->insertWidget(_ui.layout_type->count() - 3, label);
    _typeGroup.push_back((int)type);
}

void Dialog_AccountArchiveEditor::_removeTypeLabel(const int& index)
{
    QWidget* widget = QWidget::findChild<QWidget*>(std::format("lb_type_{}", index).c_str());
    _ui.layout_type->removeWidget(widget);
    delete widget;
    widget = nullptr;
    _ui.layout_type->update();
    _typeGroup.erase(std::remove(_typeGroup.begin(), _typeGroup.end(), index), _typeGroup.end());
}

void Dialog_AccountArchiveEditor::_switchEditMode()
{
    _isOnEditMode = !_isOnEditMode;
    _ui.ledit_customName->setReadOnly(!_isOnEditMode);
    _ui.ledit_comment->setReadOnly(!_isOnEditMode);
    _ui.ledit_username->setReadOnly(!_isOnEditMode);
    _ui.ledit_password->setReadOnly(!_isOnEditMode);
    _ui.ledit_nickname->setReadOnly(!_isOnEditMode);
    _ui.ledit_uid->setReadOnly(!_isOnEditMode);
    _ui.ledit_phone->setReadOnly(!_isOnEditMode);
    _ui.ledit_email->setReadOnly(!_isOnEditMode);
    _ui.tedit_note->setReadOnly(!_isOnEditMode);
    _ui.lb_state->setText(_isOnEditMode ? tr("编辑模式") : tr("只读模式"));
    _ui.lb_state->setStyleSheet(_isOnEditMode ? "color: rgb(85, 85, 255);" : "color: rgb(255, 170, 127);");
}
