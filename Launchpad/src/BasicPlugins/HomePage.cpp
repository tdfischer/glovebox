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

#include "HomePage.h"

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QGraphicsView>

HomePage::HomePage()
  : LaunchpadPage()
{
  setName("Dashboard");
}

void
HomePage::init()
{
  m_scene = new QGraphicsScene();
  m_scene->addText("Test");
  m_view = new QGraphicsView(m_scene);
  m_view->show();
  setWidget(m_view);
}

#include "HomePage.moc"

Q_EXPORT_PLUGIN2(homepage, HomePage)
