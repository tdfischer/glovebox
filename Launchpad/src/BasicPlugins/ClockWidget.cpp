#include "ClockWidget.h"

#include <QTime>

#include <QDebug>

ClockWidget::ClockWidget(QGraphicsItem* parent)
  : DashWidget(parent)
{
}

void
ClockWidget::dataUpdated(const QString &key, const QVariant &data)
{
  if (key == "Time") {
    QTime time = data.toTime();
    QTransform seconds;
    QTransform hours;
    QTransform minutes;
    m_seconds->setTransform(seconds.rotate(time.second()/60.0*360).scale(1,0.5));
    m_hours->setTransform(hours.rotate(time.hour()/24.0*360).scale(0.5,1));
    m_minutes->setTransform(minutes.rotate(time.minute()/60.0*360));
  }
}

QRectF
ClockWidget::boundingRect() const
{
  return QRectF(0, 0, 100, 100);
}

void
ClockWidget::init()
{
  timeService = ServiceManager::getService("time");
  connect(timeService,SIGNAL(dataUpdated(QString, QVariant)),this,SLOT(dataUpdated(QString, QVariant)));
  m_clock = new QGraphicsEllipseItem(0,0,100,100, this);
  QPolygonF armPoly;
  armPoly.append(QPointF(0,0));
  armPoly.append(QPointF(50,-5));
  armPoly.append(QPointF(55,0));
  armPoly.append(QPointF(50,5));
  armPoly.append(QPointF(0,0));
  m_hours = new QGraphicsPolygonItem(armPoly, this);
  m_minutes = new QGraphicsPolygonItem(armPoly, this);
  m_seconds = new QGraphicsPolygonItem(armPoly, this);
  m_hours->setBrush(QBrush(Qt::black));
  m_minutes->setBrush(QBrush(Qt::black));
  m_seconds->setBrush(QBrush(Qt::red));
  m_hours->setPos(50,50);
  m_seconds->setPos(50,50);
  m_minutes->setPos(50,50);

  //m_label = new QGraphicsTextItem(this);
  //m_label->setAlignment(Qt::AlignCenter);
}

/*void
ClockWidget::paint(QPainter* painter, const QStyleOptionGrahphicsItem* option, QWidget* widget)
{
  //TODO: Draw clock, set size hints.
}*/

#include "ClockWidget.moc"

Q_EXPORT_PLUGIN2(clockwidget, ClockWidget);