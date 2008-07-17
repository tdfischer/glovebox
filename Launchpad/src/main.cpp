#include "Launchpad.h"
#include <QtPlugin>

Q_IMPORT_PLUGIN(homepage)

int main(int argc, char **argv)
{
    Launchpad app(argc, argv);

    return app.exec();
}
