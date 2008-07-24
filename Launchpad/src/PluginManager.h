#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "Launchpad.h"
#include "ServiceManager.h"

#include <QString>
#include <QObject>
#include <QList>

class Launchpad;

class PluginManager : public QObject
{

  Q_OBJECT

  public:
    PluginManager(Launchpad* pad);
    void loadPlugin(const QString &lib);
    void loadPlugins();
    QList<QObject*> loadedPlugins();

  signals:
    void pluginsLoaded();

  protected:
    void loadPlugin(QObject* plugin);

  private:
    QList<QObject*> pluginList;
    Launchpad* launchpad;
};

#endif
