#include <format>
#include <sstream>
#include "State.h"
#include "Path.h"
#include "File.h"
#include "Tools.h"

bool State::listenPasteShortcuts = false;
std::string State::contentWaitToWriteClipboard = "";
std::string State::currentPassword = "";
unsigned int State::currentDataCount = 0;
bool State::needUserPassword = true;

State::State() {}
State::~State() {}

State::Settings State::settings;
State::AESArgs State::aesArgs;
std::map<unsigned int, std::string> State::data;

void State::updateSettingsFromFile(void)
{
    std::string settingFilePath = Path::mkpath(Path::DEPENDENCY_FILES, SETTING_FILE_NAME);
    File file = File(settingFilePath, std::ios::in);
    std::vector<std::string> lines = file.readLines(true, "#");
    std::vector<std::string> vec;
    for (auto& line : lines)
    {
        vec = Tools::split(line, "=", 1, false);
        // 功能设置读取
        if (vec[0] == "windowCloseAction") settings.windowCloseAction = std::stoi(vec[1]);
        else if (vec[0] == "hideMainWindowWhenStart") std::istringstream(vec[1]) >> std::boolalpha >> settings.hideMainWindowWhenStart;
        else if (vec[0] == "showSystemMessageWhenStart") std::istringstream(vec[1]) >> std::boolalpha >> settings.showSystemMessageWhenStart;
        else if (vec[0] == "clipboardWriteContent") settings.clipboardWriteContent = vec[1];
        else if (vec[0] == "clipboardWriteMode") settings.clipboardWriteMode = vec[1];
        // 安全设置读取
        else if (vec[0] == "passwordRequirement") settings.passwordRequirement = vec[1];
        else if (vec[0] == "userPassword") settings.userPassword = vec[1];
    }
}

void State::writeSettingsToFile(void)
{
    std::string settingFilePath = Path::mkpath(Path::DEPENDENCY_FILES, SETTING_FILE_NAME);
    File file = File(settingFilePath, std::ios::in);
    std::vector<std::string> lines = file.readLines(false, "", false);
    std::vector<std::string> vec;
    for (auto& line : lines)
    {
        vec = Tools::split(line, "=", 1);
        if (vec.size() <= 1) continue;
        if (vec[0] == "windowCloseAction") vec[1] = std::to_string(settings.windowCloseAction);
        else if (vec[0] == "hideMainWindowWhenStart") vec[1] = settings.hideMainWindowWhenStart ? "true" : "false";
        else if (vec[0] == "showSystemMessageWhenStart") vec[1] = settings.showSystemMessageWhenStart ? "true" : "false";
        else if (vec[0] == "clipboardWriteContent") vec[1] = settings.clipboardWriteContent;
        else if (vec[0] == "clipboardWriteMode") vec[1] = settings.clipboardWriteMode;
        // 以下为安全设置
        else if (vec[0] == "passwordRequirement") vec[1] = settings.passwordRequirement;
        else if (vec[0] == "userPassword") vec[1] = settings.userPassword;
        line = std::format("{}={}", vec[0], vec[1]);
    }
    file.update(settingFilePath, std::ios::out);
    file.writeLines(lines, true);
}

void State::resetToDefaultSettings(void)
{
    settings.windowCloseAction = 0;
    settings.hideMainWindowWhenStart = false;
    settings.showSystemMessageWhenStart = true;
    settings.clipboardWriteContent = "both";
    settings.clipboardWriteMode = "listen";
}

void State::updateAESArgsFromFile(void)
{
    std::string aeskFilePath = Path::mkpath(Path::DEPENDENCY_FILES, AES_KEY_FILE_NAME);
    File file = File(aeskFilePath, std::ios::in);
    std::vector<std::string> lines = file.readLines(true, "#");
    std::vector<std::string> vec;
    for (auto& line : lines)
    {
        vec = Tools::split(line, ":", 1);
        if (vec[0] == "KEYLENGTH") aesArgs.keyLength = std::stoi(vec[1]);
        else if (vec[0] == "ITERATIONCOUNT") aesArgs.iterationCount = std::stoi(vec[1]);
        else if (vec[0] == "SALT") aesArgs.salt = vec[1];
        else if (vec[0] == "IV") aesArgs.iv = vec[1];
    }
}

void State::updateDataFromFile(void)
{
    std::string dataFilePath = Path::mkpath(Path::DEPENDENCY_FILES, DATA_FILE_NAME);
    File file = File(dataFilePath, std::ios::in);
    std::vector<std::string> lines = file.readLines(true, "#");
    unsigned int count = 0;
    for (auto& line : lines)
    {
        data[count] = line;
        count++;
    }
    currentDataCount = count;
}

void State::writeDataToFile(void)
{
    std::vector<std::string> lines;
    for (const auto& pair : data) lines.push_back(pair.second);
    std::string dataFilePath = Path::mkpath(Path::DEPENDENCY_FILES, DATA_FILE_NAME);
    File file = File(dataFilePath, std::ios::out);
    file.writeLines(lines, true, false);
}
