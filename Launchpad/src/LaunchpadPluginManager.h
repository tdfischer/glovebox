#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

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


#include "LaunchpadApp.h"
#include "ServiceManager.h"

#include <QString>
#include <QObject>
#include <QList>

class LaunchpadApp;

class LaunchpadPluginManager : public QObject
{

  Q_OBJECT

  public:
    LaunchpadPluginManager(LaunchpadApp* pad);
    void loadPlugin(const QString &lib);
    void loadPlugins();
    QList<QObject*> loadedPlugins();

  signals:
    void pluginsLoaded();

  protected:
    void loadPlugin(QObject* plugin);

  private:
    QList<QObject*> pluginList;
    LaunchpadApp* launchpad;
};

#endif