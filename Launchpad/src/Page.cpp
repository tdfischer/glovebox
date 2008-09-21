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

#include "Page.h"

#include <QLabel>
#include <QWidget>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIcon>

#include <GIcon.h>

Page::Page()
  : QObject()
{
}

Page::~Page()
{
}

void
Page::init()
{
  QWidget* panel = new QWidget();
  QWidget* text = new QWidget();
  QVBoxLayout* textLayout = new QVBoxLayout;
  QHBoxLayout* iconLayout = new QHBoxLayout;

  text->setLayout(textLayout);
  panel->setLayout(iconLayout);


  QLabel* iconView = new QLabel(panel);
  GIcon icon("help-hint");
  iconView->setPixmap(icon.pixmap(iconView->size()));

  iconLayout->addWidget(iconView);
  iconLayout->addWidget(text);

  QLabel* header = new QLabel(tr("Unable to display page"), text);
  QLabel* message = new QLabel(tr("There was an error loading the requested plugin."), text);
  header->setAlignment(Qt::AlignHCenter);
  message->setAlignment(Qt::AlignHCenter);

  QFont bigFont;
  bigFont.setBold(true);
  header->setFont(bigFont);

  textLayout->addStretch();
  textLayout->addWidget(header);
  textLayout->addWidget(message);
  textLayout->addStretch();

  header->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
  message->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

  message->setWordWrap(true);

  setWidget(panel);
}

void
Page::addDock(QDockWidget* dock)
{
  m_dockWidgets.append(dock);
  emit dockAdded(dock);
}

void
Page::removeDock(QDockWidget* dock)
{
  m_dockWidgets.removeOne(dock);
}

QList<QDockWidget*>
Page::docks() const
{
  return m_dockWidgets;
}

//TODO: Save visibility states
void
Page::hideDocks()
{
  foreach(QDockWidget* dock, m_dockWidgets) {
    dock->hide();
  }
}

void
Page::showDocks()
{
  foreach(QDockWidget* dock, m_dockWidgets) {
    dock->show();
  }
}

void
Page::hideEvent(QHideEvent* event)
{
  hideDocks();
}

void
Page::showEvent(QShowEvent* event)
{
  showDocks();
}

void
Page::setWidget(QWidget* widget)
{
  m_widget = widget;
}

QWidget*
Page::widget() const
{
  return m_widget;
}

void
Page::setName(const QString &name)
{
  m_name = QString(name);
  emit nameChanged(this, name);
}

QString
Page::name() const
{
  return m_name;
}

void
Page::setIcon(const QIcon &icon)
{
  m_icon = QIcon(icon);
  emit iconChanged(this, icon);
}

QIcon
Page::icon() const
{
  return m_icon;
}

#include "Page.moc"
