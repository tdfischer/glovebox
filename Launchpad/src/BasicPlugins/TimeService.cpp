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

#include "TimeService.h"

#include <QTimer>
#include <QStringList>
#include <QTime>
#include <QVariant>

TimeService::TimeService()
  : Service()
{
  setName("time");
  m_timer = new QTimer(this);
  connect(m_timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));
}

QStringList
TimeService::sources() const
{
  return QStringList() << "Date" << "Time";
}

void
TimeService::start()
{
  m_timer->start(1000);
  setRunning(true);
}

void
TimeService::stop()
{
  m_timer->stop();
  setRunning(false);
}

void
TimeService::timeUpdate()
{
  setData("Time", QVariant(QTime::currentTime()));
  setData("Date", QVariant(QDate::currentDate()));
}

void
TimeService::requestUpdate(const QString &key)
{
  timeUpdate();
}

#include "TimeService.moc"

Q_EXPORT_PLUGIN2(timeservice, TimeService)
