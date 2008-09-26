#include "DateWidget.h"

#include <QTime>

#include <QDebug>

DateWidget::DateWidget(QGraphicsItem* parent)
  : DashWidget(parent)
{
}

void
DateWidget::dataUpdated(const QString &key, const QVariant &data)
{
  if (key == "Date") {
    m_date->setPlainText(data.toString());
  }
}

QRectF
DateWidget::boundingRect() const
{
  return QRectF(0, 0, 200, 100);
}

void
DateWidget::init()
{
  timeService = ServiceManager::getService("time");
  connect(timeService,SIGNAL(dataUpdated(QString, QVariant)),this,SLOT(dataUpdated(QString, QVariant)));
  m_date = new QGraphicsTextItem(this);
}

/*void
DateWidget::paint(QPainter* painter, const QStyleOptionGrahphicsItem* option, QWidget* widget)
{
  //TODO: Draw clock, set size hints.
}*/

#include "DateWidget.moc"

Q_EXPORT_PLUGIN2(datewidget, DateWidget);