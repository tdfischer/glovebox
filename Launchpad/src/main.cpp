#include "Launchpad.h"
#include <QtPlugin>

Q_IMPORT_PLUGIN(homepage)
Q_IMPORT_PLUGIN(settingspage)
Q_IMPORT_PLUGIN(timeservice)
Q_IMPORT_PLUGIN(clockpage)

int main(int argc, char **argv)
{
    Launchpad app(argc, argv);

    return app.exec();
}
