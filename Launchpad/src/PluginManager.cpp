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
#include "Service.h"
#include "Page.h"
#include "PageListModel.h"

#include <config.h>

#include <QPluginLoader>
#include <QDir>
#include <QApplication>
#include <QDebug>

PluginManager *PluginManager::m_instance = 0;

PluginManager::PluginManager()
  : QObject(),
    m_pluginsLoaded(false)
{
}

void
PluginManager::loadPlugins()
{
  qDebug() << "Loading static plugins";
  foreach(QObject *plugin, QPluginLoader::staticInstances()) {
    pluginList.append(plugin);
    emit pluginLoaded(plugin);
  }

  qDebug() << "Looking for plugins in" << PLUGIN_PATH;
  QDir pluginDir = QDir(PLUGIN_PATH);

  foreach(const QString file, pluginDir.entryList(QDir::Files))
    loadPlugin(pluginDir.absoluteFilePath(file));

  m_pluginsLoaded = true;
  emit pluginsLoaded();
}

void
PluginManager::loadPlugin(const QString &lib)
{
  qDebug() << "Loading plugins in" << lib;
  QPluginLoader loader(lib);
  QObject* plugin = loader.instance();
  if (plugin) {
    pluginList.append(plugin);
    emit pluginLoaded(plugin);
    //loadPlugin(plugin);
  } else {
    qWarning() << "Error while loading plugin:" << loader.errorString();
  }
}

bool
PluginManager::pluginsAreLoaded() const
{
  return m_pluginsLoaded;
}

QList<QObject*>
PluginManager::loadedPlugins() const
{
  return pluginList;
}

#include "PluginManager.moc"
