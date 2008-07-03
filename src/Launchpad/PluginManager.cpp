#include "PluginManager.h"
#include "LaunchpadService.h"
#include "LaunchpadPlugin.h"

#include <QPluginLoader>
#include <QDir>
#include <QApplication>

PluginManager::PluginManager(Launchpad* pad)
  : launchpad(pad),
    services()
{
  
}

void
PluginManager::loadPlugins()
{
  foreach(QObject *plugin, QPluginLoader::staticInstances())
    loadPlugin(plugin);
  QDir pluginDir = QDir(QApplication::applicationDirPath());
  
  pluginDir.cd("plugins");
  
  foreach(QString file, pluginDir.entryList(QDir::Files))
    loadPlugin(pluginDir.absoluteFilePath(file));
}

void
PluginManager::loadPlugin(const QString &lib)
{
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
    QStringList pages = iLaunchpad->pages();
    foreach(QString page, pages)
      launchpad->addPage(iLaunchpad->requestPage(page), page);
  }
  LaunchpadService *iService = qobject_cast<LaunchpadService *>(plugin);
  if (iService) {
    services->add(iService);
  }
}
