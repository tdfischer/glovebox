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

  /*painter->setBrush(backgroundBrush);
  painter->drawRoundedRect(option.rect.adjusted(2, 2, -2, -2), 5, 5);*/

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
