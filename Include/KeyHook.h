#pragma once

#include <Windows.h>
#include <functional>

namespace Core
{
    class KeyHook;
}

class KeyHook
{
public:
    KeyHook();
    ~KeyHook();

    static LRESULT CALLBACK keyHookEvent(int nCode, WPARAM wParam, LPARAM lParam);

    static void setKeyPressCallBack(std::function<void(int)> func);
    static void setKeyReleaseCallBack(std::function<void(int)> func);

    static void enableHook(void);
    static void disableHook(void);

private:
    static bool _lock;
    static HHOOK _keyboard_hook;
    static std::function<void(int)> _keyPressCallBackFunc;
    static std::function<void(int)> _KeyReleaseCallBackFunc;
};
