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

#include "ServiceManager.h"
#include "InvalidService.h"
#include "PluginManager.h"
#include <QDebug>

ServiceManager *ServiceManager::m_instance = 0;

ServiceManager::ServiceManager()
  : serviceList()
{
  connect(PluginManager::instance(), SIGNAL(pluginLoaded(QObject*)), this, SLOT(loadPlugin(QObject*)));
}

void
ServiceManager::add(LaunchpadService* service)
{
  serviceList.insert(service->name(),service);
  service->start();
}

void
ServiceManager::loadPlugin(QObject* plugin)
{
  LaunchpadService* iService = qobject_cast<LaunchpadService*>(plugin);
  if (iService) {
    qDebug() << "Found service plugin" << iService->name();
    add(iService);
  }
}

LaunchpadService*
ServiceManager::getService(const QString& name)
{
  ServiceManager* sm = ServiceManager::instance();
  return sm->findService(name);
}

LaunchpadService*
ServiceManager::findService(const QString& name) const
{
  if (serviceList[name]==0)
    return new InvalidService();
  else
    return serviceList[name];
}

#include "ServiceManager.moc"
