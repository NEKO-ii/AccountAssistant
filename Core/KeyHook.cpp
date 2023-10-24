#include "KeyHook.h"
//#include <qglobal.h>

bool KeyHook::_lock = true;
HHOOK KeyHook::_keyboard_hook = NULL;
std::function<void(int)> KeyHook::_keyPressCallBackFunc = NULL;
std::function<void(int)> KeyHook::_KeyReleaseCallBackFunc = NULL;

KeyHook::KeyHook()
{
    //Q_ASSERT(!_keyboard_hook);
    // 向Windows消息循环中注册钩子处理函数
    _keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)keyHookEvent, GetModuleHandle(NULL), 0);
}

KeyHook::~KeyHook()
{
    if (_keyboard_hook != nullptr) UnhookWindowsHookEx(_keyboard_hook);
}

LRESULT CALLBACK KeyHook::keyHookEvent(int code, WPARAM wParam, LPARAM lParam)
{
    if (code < 0) return CallNextHookEx(_keyboard_hook, code, wParam, lParam);
    // 按键键码传给回调函数
    if (!_lock) {
        if (wParam == WM_KEYDOWN) _keyPressCallBackFunc(((KBDLLHOOKSTRUCT*)lParam)->vkCode);
        else if (wParam == WM_KEYUP) _KeyReleaseCallBackFunc(((KBDLLHOOKSTRUCT*)lParam)->vkCode);
    }
    // 放行
    return CallNextHookEx(_keyboard_hook, code, wParam, lParam);
}

void KeyHook::setKeyPressCallBack(std::function<void(int)> func)
{
    _keyPressCallBackFunc = func;
}

void KeyHook::setKeyReleaseCallBack(std::function<void(int)> func)
{
    _KeyReleaseCallBackFunc = func;
}

void KeyHook::enableHook(void)
{
    if (_lock) _lock = false;
}

void KeyHook::disableHook(void)
{
    if (!_lock) _lock = true;
}
