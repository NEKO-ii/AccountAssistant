#include "AccountAssistant.h"
#include <QtWidgets/QApplication>
#include "Path.h"
#include "State.h"

int main(int argc, char* argv[])
{
    Path::init();
    State::updateSettingsFromFIle();

    QApplication app(argc, argv);
    AccountAssistant window;
    //window.show();

    return app.exec();
}
