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

#include "GpsListener.h"
#include <QDebug>
#include <QPointF>
#include <QApplication>

GpsListener::GpsListener(QObject* parent)
  : QThread(parent)
{
}

void
GpsListener::run()
{
  qDebug() << "Opening gpsd connection";
  m_gpsd = gps_open("127.0.0.1", "2947");
  if (m_gpsd == 0) {
    qDebug() << "Connection couldn't be made.";
    emit socketClosed();
    return;
  }
  qDebug() << "Connected.";
  gps_query(m_gpsd, "w=1");
  forever {
    //qDebug() << "Polling";
    gps_poll(m_gpsd);
    //qDebug() << "Poll'd.";
    //qDebug() << "Fix: " << QPointF(m_gpsd->fix.latitude,m_gpsd->fix.longitude);
    //m_lastFix = m_gpsd->fix;
    emit fixUpdated(m_gpsd->fix);
    QApplication::processEvents();
  }
  gps_close(m_gpsd);
  emit socketClosed();
}

void
GpsListener::stop()
{
  m_running = false;
}

#include "GpsListener.moc"
