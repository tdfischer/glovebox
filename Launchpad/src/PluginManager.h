#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "Launchpad.h"
#include "ServiceManager.h"

#include <QString>
#include <QObject>
#include <QList>

class Launchpad;

class PluginManager
{
  public:
    PluginManager(Launchpad* pad);
    void loadPlugin(const QString &lib);
    void loadPlugins();

  protected:
    void loadPlugin(QObject *plugin);

  private:
    QList<QObject*> pluginList;
    ServiceManager* services;
    Launchpad* launchpad;
};

#endif
