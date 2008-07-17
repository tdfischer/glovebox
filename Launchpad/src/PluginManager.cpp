#include "PluginManager.h"
#include "LaunchpadService.h"
#include "LaunchpadPlugin.h"

#include <config.h>

#include <QPluginLoader>
#include <QDir>
#include <QApplication>
#include <QDebug>

PluginManager::PluginManager(Launchpad* pad)
  : services(),
    launchpad(pad)
{
  
}

void
PluginManager::loadPlugins()
{
  qDebug() << "Loading static plugins";
  foreach(QObject *plugin, QPluginLoader::staticInstances())
    loadPlugin(plugin);

  qDebug() << "Looking for plugins in " << PLUGIN_PATH;
  QDir pluginDir = QDir(PLUGIN_PATH);

  foreach(QString file, pluginDir.entryList(QDir::Files))
    loadPlugin(pluginDir.absoluteFilePath(file));
}

void
PluginManager::loadPlugin(const QString &lib)
{
  qDebug() << "Loading plugins in " << lib;
  QPluginLoader loader(lib);
  QObject* plugin = loader.instance();
  if (plugin) {
    loadPlugin(plugin);
  }
}

void
PluginManager::loadPlugin(QObject *plugin)
{
  LaunchpadPlugin *iLaunchpad = qobject_cast<LaunchpadPlugin *>(plugin);
  if (iLaunchpad) {
    qDebug() << "Found launchpad page plugin " << iLaunchpad->name();
    QStringList pages = iLaunchpad->pages();
    qDebug() << "Available pages: " << pages;
    foreach(QString page, pages)
      launchpad->addPage(iLaunchpad->requestPage(page), page);
  }
  LaunchpadService *iService = qobject_cast<LaunchpadService *>(plugin);
  if (iService) {
    qDebug() << "Found service plugin " << iService->name();
    services->add(iService);
  }
}
