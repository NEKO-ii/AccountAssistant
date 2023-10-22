#include <format>
#include <sstream>
#include "State.h"
#include "Path.h"
#include "File.h"
#include "Tools.h"

State::State() {}
State::~State() {}

State::Settings State::settings = Settings();

void State::updateSettingsFromFIle(void)
{
    std::string settingFilePath = Path::mkpath(Path::DEPENDENCY_FILES, "settings.ini");
    File file = File(settingFilePath);
    std::vector<std::string> lines = file.readLines(true, "#");
    std::vector<std::string> vec;
    for (auto& line : lines)
    {
        vec = Tools::split(line, "=", 1);
        if (vec[0] == "windowCloseAction") settings.windowCloseAction = std::stoi(vec[1]);
        else if (vec[0] == "hideOnStart") std::istringstream(vec[1]) >> std::boolalpha >> settings.hideOnStart;
    }
}

void State::writeSettingsToFile(void)
{
    std::string settingFilePath = Path::mkpath(Path::DEPENDENCY_FILES, "settings.ini");
    File file = File(settingFilePath, std::ios::in);
    std::vector<std::string> lines = file.readLines(false, "", false);
    std::vector<std::string> vec;
    for (auto& line : lines)
    {
        vec = Tools::split(line, "=", 1);
        if (vec.size() <= 1) continue;
        if (vec[0] == "windowCloseAction") vec[1] = std::to_string(settings.windowCloseAction);
        else if (vec[0] == "hideOnStart") vec[1] = settings.hideOnStart ? "true" : "false";
        line = std::format("{}={}", vec[0], vec[1]);
    }
    file.update(settingFilePath, std::ios::out);
    file.writeLines(lines, true, true);
}
