#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

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

#include <QMap>
#include <QString>
#include "LaunchpadService.h"

//class PluginManager;

class ServiceManager
{

  friend class PluginManager;

  public:
    static ServiceManager *instance() {
      if (m_instance == 0)
        m_instance = new ServiceManager();
      return (m_instance);
    }

    ~ServiceManager() {
      m_instance = 0;
    }

    //bool loadService(const QString &name);
    void startService(const QString &name);
    void stopService(const QString &name);

    static LaunchpadService* getService(const QString &name);

  protected:
    LaunchpadService* findService(const QString &name) const;
    void add(LaunchpadService* service);

  private:
    ServiceManager();
    static ServiceManager *m_instance;
    QMap<QString, LaunchpadService*> serviceList;
};

#endif
