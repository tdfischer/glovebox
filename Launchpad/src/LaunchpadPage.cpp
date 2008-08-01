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

#include "LaunchpadPage.h"

#include <QLabel>
#include <QWidget>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIcon>

LaunchpadPage::LaunchpadPage()
  : QObject()
{
}

LaunchpadPage::~LaunchpadPage()
{
}

void
LaunchpadPage::init()
{
  QWidget* panel = new QWidget();
  QWidget* text = new QWidget();
  QVBoxLayout* textLayout = new QVBoxLayout;
  QHBoxLayout* iconLayout = new QHBoxLayout;

  text->setLayout(textLayout);
  panel->setLayout(iconLayout);


  QLabel* iconView = new QLabel(panel);
  QPixmap icon("/opt/Glovebox/share/icons/help-hint.png"); //TODO: Icon manager
  iconView->setPixmap(icon);

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
LaunchpadPage::addDock(QDockWidget* dock)
{
  m_dockWidgets.append(dock);
  emit dockAdded(dock);
}

void
LaunchpadPage::removeDock(QDockWidget* dock)
{
  m_dockWidgets.removeOne(dock);
}

QList<QDockWidget*>
LaunchpadPage::docks() const
{
  return m_dockWidgets;
}

//TODO: Save visibility states
void
LaunchpadPage::hideDocks()
{
  foreach(QDockWidget* dock, m_dockWidgets) {
    dock->hide();
  }
}

void
LaunchpadPage::showDocks()
{
  foreach(QDockWidget* dock, m_dockWidgets) {
    dock->show();
  }
}

void
LaunchpadPage::hideEvent(QHideEvent* event)
{
  hideDocks();
}

void
LaunchpadPage::showEvent(QShowEvent* event)
{
  showDocks();
}

void
LaunchpadPage::setWidget(QWidget* widget)
{
  m_widget = widget;
}

QWidget*
LaunchpadPage::widget() const
{
  return m_widget;
}

void
LaunchpadPage::setName(const QString &name)
{
  m_name = QString(name);
  emit nameChanged(this, name);
}

QString
LaunchpadPage::name() const
{
  return m_name;
}

void
LaunchpadPage::setIcon(const QIcon &icon)
{
  m_icon = QIcon(icon);
  emit iconChanged(this, icon);
}

QIcon
LaunchpadPage::icon() const
{
  return m_icon;
}

#include "LaunchpadPage.moc"
