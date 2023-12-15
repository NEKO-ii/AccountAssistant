#pragma once

#include <string>
#include <map>

namespace Core
{
    class State;
}

class State
{
public:
    enum WindowCloseAction
    {
        HIDE, CLOSE
    };

    struct Settings
    {
        // 功能设置
        int windowCloseAction;
        bool hideMainWindowWhenStart;
        bool showSystemMessageWhenStart;
        std::string clipboardWriteContent;
        std::string clipboardWriteMode;
        // 安全设置
        bool enableMultiPasswordMode;
        std::string multiPasswordMode;
        std::string passwordRequirement;
    };

    struct AESArgs
    {
        int keyLength;
        int iterationCount;
        std::string salt;
        std::string iv;
    };

    // 存储软件全局设置
    static Settings settings;
    // 存储AES加解密参数
    static AESArgs aesArgs;
    // 存储加密数据
    static std::map<unsigned int, std::string> data;

    static bool listenPasteShortcuts;
    static std::string contentWaitToWriteClipboard;
    static std::string currentPassword;
    static unsigned int currentDataCount;
    static bool needUserPassword;

    /**
     * 从设置文件读取设置并更新全局设置参数
     */
    static void updateSettingsFromFile(void);

    /**
     * \brief 将全局设置参数写入到设置文件内
     */
    static void writeSettingsToFile(void);
    /**
     * 将全局设置参数重置为默认
     */
    static void resetToDefaultSettings(void);

    static void updateAESArgsFromFile(void);

    static void updateDataFromFile(void);
    static void writeDataToFile(void);

private:
    State();
    ~State();
};
