#include "Launchpad.h"
#include <QtPlugin>

Q_IMPORT_PLUGIN(homepage)
Q_IMPORT_PLUGIN(settingspage)

int main(int argc, char **argv)
{
    Launchpad app(argc, argv);

    return app.exec();
}
