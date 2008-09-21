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

#include "PageListModel.h"

#include "Page.h"

PageListModel::PageListModel(QObject* parent)
  : QAbstractListModel(parent),
    m_pages()
{
}

void
PageListModel::addPage(Page* page)
{
  page->init();
  m_pages.append(page);
  emit pageAdded(page);
}

int
PageListModel::rowCount(const QModelIndex &parent) const
{
  return m_pages.count();
}

QVariant
PageListModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  if (index.row() >= m_pages.size())
    return QVariant();

  if (role == Qt::DisplayRole)
    return m_pages.at(index.row())->name();
  else if (role == Qt::DecorationRole)
    return m_pages.at(index.row())->icon();
  else if (role == WidgetRole)
    return QVariant::fromValue(m_pages.at(index.row())->widget());
  else if (role == Qt::SizeHintRole)
    return QVariant(QSize(64,64));
  else if (role == DockRole)
    return QVariant::fromValue(m_pages.at(index.row())->docks());
  else
    return QVariant();
}

Page*
PageListModel::page(const QModelIndex &index) const
{
  return m_pages.at(index.row());
}

#include "PageListModel.moc"
