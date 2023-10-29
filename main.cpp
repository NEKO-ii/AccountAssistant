#include "AccountAssistant.h"
#include <QtWidgets/QApplication>
#include "Path.h"
#include "State.h"

int main(int argc, char* argv[])
{
    Path::init();
    State::updateSettingsFromFile();
    State::updateAESArgsFromFile();
    State::updateDataFromFile();

    QApplication app(argc, argv);
    AccountAssistant window;
    if (!State::settings.hideMainWindowWhenStart) window.show();

    return app.exec();
}
