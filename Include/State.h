#pragma once
#include <map>

namespace Core
{
    class State;
}

/**
 * 系统状态类,用于保存表示当前运行状态的全局属性以及软件设置
 */
class State
{
public:
    enum WindowCloseAction
    {
        HIDE, CLOSE
    };

    struct Settings
    {
        int windowCloseAction;
    };

    static Settings settings;

    static void updateSettingsFromFIle(void);
    static void writeSettingsToFile(void);

private:
    State();
    ~State();
};
