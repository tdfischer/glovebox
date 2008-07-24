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

#include "SettingsPage.h"

#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QStackedWidget>
#include <QListWidget>
#include <QIcon>
#include <QWidget>
#include <QLabel>

SettingsPage::SettingsPage()
  : LaunchpadPage()
{
  setName("Settings");
  //setIcon(QIcon("/opt/Glovebox/share/icons/configure.png"));
}

void
SettingsPage::init()
{
  setIcon(QIcon("/opt/Glovebox/share/icons/configure.png"));
  m_page = new QWidget();
  QHBoxLayout* layout = new QHBoxLayout(m_page);
  m_page->setLayout(layout);

  m_selector = new QListWidget(m_page);
  QListWidgetItem* testItem = new QListWidgetItem(QIcon("/opt/Glovebox/share/icons/help-hint.png"), "Hints", m_selector);
  m_selector->setViewMode(QListView::IconMode);

  m_pages = new QStackedWidget(m_page);

  layout->addWidget(m_selector);
  layout->addWidget(m_pages);
  setWidget(m_page);
}

#include "SettingsPage.moc"

Q_EXPORT_PLUGIN2(settingspage, SettingsPage)
