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

#include "GpsService.h"

#include <QPointF>

Q_DECLARE_METATYPE(gps_fix_t);

GpsService::GpsService()
  : LaunchpadService()
{
  setName("gps");
  qRegisterMetaType<gps_fix_t>();
  m_listener = new GpsListener(this);
  connect(m_listener, SIGNAL(fixUpdated(gps_fix_t)), this, SLOT(updatedFix(gps_fix_t)));
  connect(m_listener, SIGNAL(socketClosed()), this, SLOT(listenerStopped()));
}

void
GpsService::start()
{
  m_listener->start();
  setRunning(true);
}

void
GpsService::stop()
{
  m_listener->stop();
  setRunning(false);
}

void
GpsService::updatedFix(const gps_fix_t fix)
{
  setData("Position",QPointF(fix.latitude,fix.longitude));
  setData("Altitude",fix.altitude);
  setData("Speed", fix.speed);

  QString fixType;
  switch(fix.mode) {
    case MODE_NOT_SEEN:
    case MODE_NO_FIX:
      fixType = "None";
      break;
    case MODE_2D:
      fixType = "2D";
      break;
    case MODE_3D:
      fixType = "3D";
      break;
  }
  setData("Fix", fixType);
}

void
GpsService::listenerStopped()
{
  stop();
}

Q_EXPORT_PLUGIN2(gpsservice, GpsService)

#include "GpsService.moc"
