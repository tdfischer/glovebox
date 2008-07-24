#include "PluginManager.h"
#include "LaunchpadService.h"
#include "LaunchpadPage.h"

#include <config.h>

#include <QPluginLoader>
#include <QDir>
#include <QApplication>
#include <QDebug>

PluginManager::PluginManager(Launchpad* pad)
  : launchpad(pad)
{
}

void
PluginManager::loadPlugins()
{
  qDebug() << "Loading static plugins";
  foreach(QObject *plugin, QPluginLoader::staticInstances())
    loadPlugin(plugin);

  qDebug() << "Looking for plugins in" << PLUGIN_PATH;
  QDir pluginDir = QDir(PLUGIN_PATH);

  foreach(QString file, pluginDir.entryList(QDir::Files))
    loadPlugin(pluginDir.absoluteFilePath(file));

  emit pluginsLoaded();
}

void
PluginManager::loadPlugin(const QString &lib)
{
  qDebug() << "Loading plugins in" << lib;
  QPluginLoader loader(lib);
  QObject* plugin = loader.instance();
  if (plugin) {
    loadPlugin(plugin);
  }
}

void
PluginManager::loadPlugin(QObject* plugin)
{
  pluginList.append(plugin);
  LaunchpadPage* iPage = qobject_cast<LaunchpadPage*>(plugin);
  if (iPage) {
    qDebug() << "Found launchpad page plugin" << iPage->name();
    launchpad->addPage(iPage);
  }
  LaunchpadService* iService = qobject_cast<LaunchpadService*>(plugin);
  if (iService) {
    qDebug() << "Found service plugin" << iService->name();
    ServiceManager::instance()->add(iService);
  }
}

#include "PluginManager.moc"
