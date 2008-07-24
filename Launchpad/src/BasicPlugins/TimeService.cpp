#include "TimeService.h"

#include <QTimer>
#include <QStringList>
#include <QTime>
#include <QVariant>

TimeService::TimeService()
  : LaunchpadService()
{
  setName("time");
  m_timer = new QTimer(this);
  connect(m_timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));
}

QStringList
TimeService::sources() const
{
  return QStringList() << "Date";
}

void
TimeService::start()
{
  m_timer->start(1000);
  setRunning(true);
}

void
TimeService::stop()
{
  m_timer->stop();
  setRunning(false);
}

void
TimeService::timeUpdate()
{
  setData("Time", QVariant(QTime::currentTime()));
}

void
TimeService::requestUpdate(const QString &key)
{
  timeUpdate();
}

#include "TimeService.moc"

Q_EXPORT_PLUGIN2(timeservice, TimeService)
