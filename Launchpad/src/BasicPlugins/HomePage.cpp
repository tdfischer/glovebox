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
#include <QGraphicsGridLayout>
#include <QPainter>
#include <PluginManager.h>
#include <GIcon.h>

HomePage::HomePage()
  : Page()
{
  setName("Dashboard");
}

void
HomePage::init()
{
  setIcon(GIcon("start-here"));
  m_scene = new QGraphicsScene();
  m_view = new QGraphicsView(m_scene);
  m_view->show();
  connect(PluginManager::instance(), SIGNAL(pluginsLoaded()), this, SLOT(loadWidgets()));
  connect(PluginManager::instance(), SIGNAL(pluginLoaded(QObject*)), this, SLOT(loadWidget(QObject*)));
  m_layout = new QGraphicsGridLayout();
  m_container = new QGraphicsWidget();
  m_scene->addItem(m_container);
  m_view->setRenderHint( QPainter::Antialiasing );
  setWidget(m_view);
}

void
HomePage::loadWidgets()
{
  foreach(QObject* plugin, PluginManager::instance()->loadedPlugins()) {
    loadWidget(plugin);
  }
}

void
HomePage::loadWidget(QObject* plugin)
{
  if (PluginManager::instance()->pluginsAreLoaded()) {
    DashWidget* iWidget = qobject_cast<DashWidget*>(plugin);
    if (iWidget)
      loadWidget(iWidget);
  }
}

void
HomePage::loadWidget(DashWidget* widget)
{
  widget->init();
  m_scene->addItem(widget);
  widget->setParentItem(m_container);
  m_layout->activate();
}

#include "HomePage.moc"

Q_EXPORT_PLUGIN2(homepage, HomePage)
