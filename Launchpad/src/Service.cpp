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

#include "Service.h"

#include <QList>
#include <QVariant>
#include <QHash>
#include <QStringList>

#include <QDebug>

Service::Service()
  : QObject(),
    data(),
    m_running(false)
{
}

bool
Service::isValid()
{
  return true;
}

void
Service::setName(const QString &name)
{
  m_name = name;
}

void
Service::requestUpdate(const QString &key)
{
}

QString
Service::name() const
{
  return m_name;
}

void
Service::start()
{
  setRunning(true);
}

void
Service::stop()
{
  setRunning(false);
}

bool
Service::running()
{
  return m_running;
}

void
Service::setRunning(const bool setRun)
{
  m_running = setRun;
  qDebug() << name() << "running state:" << running();
  if (running() && !setRun)
    stop();
  if (!running() && setRun)
    start();
}

QVariant
Service::call(const QString &method, const QList<QVariant> &arguments)
{
  return QVariant();
}

void
Service::setData(const QString &key, const QVariant &newData)
{
  qDebug() << name() << "changed" << key << "to" << newData;
  data[key] = QVariant(newData);
  emit dataUpdated(key, newData);
}

QVariant
Service::query(const QString &key) const
{
  return data[key];
}

QStringList
Service::sources() const
{
  return data.keys();
}

QStringList
Service::methods() const
{
  return QStringList();
}

#include "Service.moc"
