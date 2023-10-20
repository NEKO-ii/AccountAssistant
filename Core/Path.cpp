#include "Path.h"
#include <filesystem>
#include <format>
#include <direct.h>

std::map<Path::Key, std::string> Path::_path;
bool Path::_hasBeenInitialized = false;

Path::Path() {}
Path::~Path() {}

void Path::init()
{
    if (_hasBeenInitialized) return;
    char buff[256];
    char* result = getcwd(buff, 256);
    if (result != 0)
    {
        _path[Key::WORK_DIR] = std::string(result);
        _path[Key::CORE] = _path[Key::WORK_DIR] + "\\Core";
        _path[Key::DATABASE] = _path[Key::WORK_DIR] + "\\Database";
        _path[Key::DEPENDENCY_FILES] = _path[Key::WORK_DIR] + "\\DependencyFiles";
        _path[Key::INCLUDE] = _path[Key::WORK_DIR] + "\\Include";
        _path[Key::UI] = _path[Key::WORK_DIR] + "\\Ui";

        checkPathIntegrity();
        _hasBeenInitialized = true;
    }
    else {
        //TODO: 未找到工作目录时处理
    }
}

std::string Path::get(Key key)
{
    return _path.at(key);
}

void Path::set(Key key, std::string value)
{
    /*auto it = _path.find(key);
    if (it != _path.end()) {
        it->second = value;
    }
    else {
        _path[key] = value;
    }*/
    _path[key] = value;
}

std::string Path::mkpath(Key key, const std::string& extendPath)
{
    return std::format("{}\\{}", _path[key], extendPath);
}

std::string Path::mkpath(Key key, const std::initializer_list<std::string>& extendPaths)
{
    std::string path = _path[key];
    for (const std::string* extpath = extendPaths.begin(); extpath != extendPaths.end(); extpath++)
    {
        path = std::format("{}\\{}", path, *extpath);
    }
    return path;
}

void Path::checkPathIntegrity()
{
    for (auto it = _path.begin(); it != _path.end(); it++)
    {
        if (!std::filesystem::exists(it->second))
        {
            std::filesystem::create_directories(it->second);
        }
    }
}
