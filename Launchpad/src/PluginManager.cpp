/**
 * Copyright (C) 2008 Trever Fischer <wm161@wm161.net>
 *
 * This file is part of Glovebox.
 *
 *  Glovebox is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Glovebox is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Glovebox.  If not, see <http://www.gnu.org/licenses/>.
*/

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
