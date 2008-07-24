#ifndef PAGELISTDELEGATE_H
#define PAGELISTDELEGATE_H

#include <QAbstractItemDelegate>

class PageListDelegate : public QAbstractItemDelegate
{
  Q_OBJECT

  public:
    PageListDelegate(QObject* parent = 0);

    void paint(QPainter* painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif
