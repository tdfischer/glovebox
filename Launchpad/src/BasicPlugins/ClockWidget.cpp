#include "ClockWidget.h"

ClockWidget::ClockWidget(QGraphicsItem* parent)
  : DashWidget(parent)
{
}

void
ClockWidget::dataUpdated(const QString &key, const QVariant &data)
{
  if (key == "Time") {
    m_label->setPlainText(data.toString());
  }
}

void
ClockWidget::init()
{
  timeService = ServiceManager::getService("time");
  timeService->connectData("Time",this);
  m_label = new QGraphicsTextItem(this);
  //m_label->setAlignment(Qt::AlignCenter);
}

#include "ClockWidget.moc"

Q_EXPORT_PLUGIN2(clockwidget, ClockWidget);