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

#include "MapPage.h"

#include <QWidget>
#include <QSplitter>
#include <QLabel>
#include <QDockWidget>

#include <ServiceManager.h>

#include <marble/MarbleControlBox.h>

#include <GIcon.h>

MapPage::MapPage()
  : Page()
{
  setName("Map");
}

void
MapPage::init()
{
  setIcon(GIcon("marble"));
  map = new MarbleWidget;
  map->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");
  map->setShowGps(true);
  map->setDownloadUrl( "http://download.kde.org/apps/marble/" );

  setWidget(map);

  QDockWidget* dock = new QDockWidget("Compass");
  addDock(dock);

  compass = new CompassWidget(dock);
  dock->setWidget(compass);
  
  dock = new QDockWidget("Signal");
  addDock(dock);
  bars = new SignalWidget(dock);
  dock->setWidget(bars);
  bars->setMaxStrength(4);
  
  connect(ServiceManager::getService("gps"), SIGNAL(dataUpdated(const QString, const QVariant)), this, SLOT(gpsUpdate(const QString, const QVariant)));
}

void
MapPage::gpsUpdate(const QString &key, const QVariant &data)
{
  if (key == "Direction")
    compass->setDirection(data.toDouble());
  if (key == "Signal")
    bars->setStrength(data.toInt());
}

Q_EXPORT_PLUGIN2(gpspage, MapPage)

#include "MapPage.moc"
