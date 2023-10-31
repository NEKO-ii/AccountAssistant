#pragma once

#include <string>
#include <map>

#define SETTING_FILE_NAME "settings.ini"
#define AES_KEY_FILE_NAME "aesk.txt"
#define DATA_FILE_NAME "data.txt"
//#define DATA_FILE_NAME "archive.tdat"

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
        int windowCloseAction;
        bool hideMainWindowWhenStart;
        bool showSystemMessageWhenStart;
        std::string clipboardWriteContent;
        std::string clipboardWriteMode;
    };

    struct AESArgs
    {
        int keyLength;
        int iterationCount;
        std::string salt;
        std::string iv;
        std::string password;
    };

    // 存储软件全局设置
    static Settings settings;
    // 存储AES加解密参数
    static AESArgs aesArgs;
    // 存储加密数据
    static std::map<unsigned int, std::string> data;

    static bool listenPasteShortcuts;
    static std::string contentWaitToWriteClipboard;
    static unsigned int currentDataCount;

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
