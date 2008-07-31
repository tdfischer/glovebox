#ifndef PAGELISTMODEL_H
#define PAGELISTMODEL_H

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

#include <QAbstractListModel>
#include <QIcon>

namespace Launchpad
{

class LaunchpadPage;

class PageListModel : public QAbstractListModel
{

  Q_OBJECT


  public:
    enum UserRoles { WidgetRole = Qt::UserRole };
    PageListModel(QObject* parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    LaunchpadPage* page(const QModelIndex &index) const;

    void addPage(LaunchpadPage* page);

  signals:
    void pageAdded(LaunchpadPage* page);

  private:
    QList<LaunchpadPage*> m_pages;
};

}

#endif
