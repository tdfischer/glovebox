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

#include "LaunchpadService.h"

#include <QList>
#include <QVariant>
#include <QHash>
#include <QStringList>

#include <QDebug>

LaunchpadService::LaunchpadService()
  : QObject(),
    data(),
    m_running(false)
{
}

bool
LaunchpadService::isValid()
{
  return true;
}

void
LaunchpadService::setName(const QString &name)
{
  m_name = name;
}

void
LaunchpadService::requestUpdate(const QString &key)
{
}

QString
LaunchpadService::name() const
{
  return m_name;
}

void
LaunchpadService::start()
{
  setRunning(true);
}

void
LaunchpadService::stop()
{
  setRunning(false);
}

bool
LaunchpadService::running()
{
  return m_running;
}

void
LaunchpadService::setRunning(const bool setRun)
{
  m_running = setRun;
  qDebug() << name() << "running state:" << running();
  if (running() && !setRun)
    stop();
  if (!running() && setRun)
    start();
}

QVariant
LaunchpadService::call(const QString &method, const QList<QVariant> &arguments)
{
  return QVariant();
}

void
LaunchpadService::setData(const QString &key, const QVariant &newData)
{
  qDebug() << name() << "changed" << key << "to" << newData;
  data[key] = QVariant(newData);
  emit dataUpdated(key, newData);
}

QVariant
LaunchpadService::query(const QString &key) const
{
  return data[key];
}

QStringList
LaunchpadService::sources() const
{
  return data.keys();
}

QStringList
LaunchpadService::methods() const
{
  return QStringList();
}

#include "LaunchpadService.moc"
