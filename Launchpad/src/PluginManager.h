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
#include "PageListModel.h"

#include <QString>
#include <QObject>
#include <QList>

namespace Launchpad
{

class LaunchpadApp;

class PluginManager : public QObject
{

  Q_OBJECT

  public:
    static PluginManager *instance() {
      if (m_instance == 0)
        m_instance = new PluginManager();
      return (m_instance);
    }

    /*~PluginManager() {
      m_instance = 0;
    }*/

    void loadPlugin(const QString &lib);
    void loadPlugins();
    QList<QObject*> loadedPlugins();
    PageListModel* pageModel() const;

  signals:
    void pluginsLoaded();

  protected:
    void loadPlugin(QObject* plugin);

  private:
    PluginManager();
    static PluginManager *m_instance;
    QList<QObject*> pluginList;
    PageListModel* m_pageList;
};

}

#endif
