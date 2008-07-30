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

#include "PageListDelegate.h"

#include <QPainter>
#include <QFontMetrics>
#include <QBrush>

#include <QDebug>

PageListDelegate::PageListDelegate(QObject* parent)
  : QAbstractItemDelegate()
{
}

void
PageListDelegate::paint(QPainter* painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  painter->save();
  painter->setRenderHint(QPainter::Antialiasing, true);
  QIcon icon = index.data(Qt::DecorationRole).value<QIcon>();
  QString title = index.data(Qt::DisplayRole).toString();

  QFontMetrics fm(painter->font());
  title = fm.elidedText(title, Qt::ElideRight, option.rect.width());

  painter->save();

  if (option.state == QStyle::State_Selected) {
    painter->setBrush(option.palette.color(QPalette::Highlight));
    painter->drawRect(option.rect);
  }

  QGradient backgroundGradient(QLinearGradient(0,0,0,1));
  backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
  backgroundGradient.setColorAt(0, option.palette.color(QPalette::Midlight));
  backgroundGradient.setColorAt(1, option.palette.color(QPalette::Dark));
  QGradient borderGradient(backgroundGradient);
  borderGradient.setColorAt(0, option.palette.color(QPalette::Mid));
  borderGradient.setColorAt(1, option.palette.color(QPalette::Button));

  QBrush backgroundBrush(backgroundGradient);
  QBrush borderBrush(borderGradient);
  QPen borderPen(borderBrush, 3);
  borderPen.setJoinStyle(Qt::RoundJoin);
  
  painter->setPen(borderPen);
  painter->setBrush(backgroundBrush);
  painter->drawRoundedRect(option.rect, 5, 5);

  painter->restore();

  icon.paint(painter, option.rect, Qt::AlignCenter | Qt::AlignTop);

  painter->setPen(option.palette.color(QPalette::Light));
  QRect textArea(option.rect);
  QRect textSize = fm.boundingRect(title);
  textArea.setTop(textArea.bottom()-fm.height());
  painter->drawText(textArea, Qt::AlignCenter, title);
  painter->restore();
}

QSize
PageListDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  //qDebug() << "SizeHint size:" << option.rect;
  return QSize(64, 64);
}

#include "PageListDelegate.moc"
