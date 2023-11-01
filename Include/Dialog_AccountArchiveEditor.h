#pragma once

#include "ui_Dialog_AccountArchiveEditor.h"
#include "AccountItem.h"
#include "Define.h"
#include <QWidget>
#include <vector>

class Dialog_AccountArchiveEditor : public QDialog
{
    Q_OBJECT

public:
    enum struct OpenMode { CREATE, UPDATE };

    /**
     * 创建对话框
     *
     * \param parent 父对象指针
     * \param id 唯一存档id
     * \param item 存档对象,使用包含该参数的构造即视为UPDATE模式打开
     */
    Dialog_AccountArchiveEditor(QWidget* parent, unsigned int id, const AccountItem& item);
    Dialog_AccountArchiveEditor(QWidget* parent, unsigned int id);
    ~Dialog_AccountArchiveEditor();

    inline AccountItem getAccountItem(void) { return _item; };

private:
    Ui::Dialog_AccountArchiveEditor _ui;
    unsigned int _id;
    AccountItem _item;
    OpenMode _openMode;
    std::vector<int> _typeGroup;
    // 账户类型标签数量限制
    static constexpr int _ACCOUNT_TYPE_GROUP_LIMIT = 3;
    std::string _currentTypeControlBtnAction;
    bool _isEncyInfoHide;
    bool _isOnEditMode;
    bool _isDefaultTypeLabelRemoved;

    /**
     * 链接信号槽
     *
     */
    void _connect(void);
    /**
     * 初始化组件状态
     *
     */
    void _initWidgetState(void);
    /**
     * 检查输入是否正确
     *
     * \return 结果布尔值
     */
    bool _check(void);
    /**
     * 初始化数据对象
     *
     * \param data 未解密的数据字符串
     */
    void _initData(void);
    /**
     * 更新数据对象
     *
     */
    void _updateDataItem(void);
    /**
     * 更新类型标签控制按钮
     *
     */
    void _updateTypeControlBtn(void);
    /**
     * 插入类型标签
     *
     * \param type
     */
    void _insertTypeLabel(const Define::AccountType& type);
    /**
     * 删除类型标签
     *
     * \param index 当前ComboBox索引
     */
    void _removeTypeLabel(const int& index);
    /**
     * 设置编辑模式
     *
     * \param bool modeFlag 模式标记
     */
    void _switchEditMode();

signals:
    void signal_save(unsigned int id, AccountItem item, OpenMode mode);
};
