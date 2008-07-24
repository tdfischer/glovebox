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

#include "ClockPage.h"

#include <ServiceManager.h>
#include <LaunchpadService.h>

#include <QLabel>
#include <QVariant>

ClockPage::ClockPage()
  : LaunchpadPage()
{
  setName("Clock");
}

void
ClockPage::init()
{
  QFont font;
  font.setPointSize(72);
  QLabel* label = new QLabel();
  label->setFont(font);
  label->setAlignment(Qt::AlignCenter);
  setWidget(label);
  LaunchpadService* time = ServiceManager::getService("time");
  time->connectData("Time", this);
}

void
ClockPage::dataUpdated(const QString &key, const QVariant &data)
{
  QLabel* label = qobject_cast<QLabel*>(widget());
  label->setText(data.toString());
}

#include "ClockPage.moc"

Q_EXPORT_PLUGIN2(clockpage, ClockPage)
