#pragma once

#include <string>
#include <map>

namespace Core
{
    class Path;
}

class Path
{
public:
    enum Key
    {
        WORK_DIR, CORE, DATABASE, DEPENDENCY_FILES, INCLUDE, UI
    };

    /**
     * 初始化系统路径
     *
     */
    static void init(void);
    /**
     * 获取系统路径.
     *
     * \param key 使用本类枚举,代表软件工作路径以及一级子路径
     * \return 返回路径存档
     */
    static std::string get(Key key);
    /**
     * 设置/更新/新增路径索引.
     *
     * \param key 使用本类枚举,代表软件工作路径以及一级子路径
     * \param value 设置值
     */
    static void set(Key key, std::string value);
    /**
     * 构建路径.
     *
     * \param key 使用本类枚举,代表软件工作路径以及一级子路径
     * \param extendPath 额外路径列表,起始位置无需"\\\\"
     * \return 完整路径字符串
     */
    static std::string mkpath(Key key, const std::string& extendPath);
    /**
     * 构建路径.
     *
     * \param key 使用本类枚举,代表软件工作路径以及一级子路径
     * \param extendPaths 额外路径列表,使用{"path1","path2",...}输入
     * \return 完整路径字符串
     */
    static std::string mkpath(Key key, const std::initializer_list<std::string>& extendPaths);

private:
    Path();
    ~Path();

    static bool _hasBeenInitialized;
    static std::map<Key, std::string> _path;

    /**
     * 检查系统路径完整性,对缺失路径进行创建.
     *
     */
    static void checkPathIntegrity(void);
};
