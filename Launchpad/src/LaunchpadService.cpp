#include "LaunchpadService.h"

#include <QList>
#include <QVariant>
#include <QHash>
#include <QStringList>

#include <QDebug>

LaunchpadService::LaunchpadService()
  : QObject(),
    data(),
    m_running(false)
{
}

bool
LaunchpadService::isValid()
{
  return true;
}

void
LaunchpadService::setName(const QString &name)
{
  m_name = name;
}

QString
LaunchpadService::name() const
{
  return m_name;
}

void
LaunchpadService::start()
{
  setRunning(true);
}

void
LaunchpadService::stop()
{
  setRunning(false);
}

bool
LaunchpadService::running()
{
  return m_running;
}

void
LaunchpadService::setRunning(const bool setRun)
{
  m_running = setRun;
  qDebug() << name() << "running state:" << running();
  if (running() && !setRun)
    stop();
  if (!running() && setRun)
    start();
}

QVariant
LaunchpadService::call(const QString &method, const QList<QVariant> &arguments)
{
  return QVariant();
}

void
LaunchpadService::setData(const QString &key, const QVariant &newData)
{
  //qDebug() << name() << "changed" << key << "to" << newData;
  data[key] = QVariant(newData);
  emit dataUpdated(key, newData);
}

QVariant
LaunchpadService::query(const QString &key) const
{
  return data[key];
}

void
LaunchpadService::connectData(const QString &key, QObject* endpoint) const
{
  Q_UNUSED(key);
  connect(this,SIGNAL(dataUpdated(const QString, const QVariant)),endpoint,SLOT(dataUpdated(const QString, const QVariant)));
}

QStringList
LaunchpadService::sources() const
{
  return QStringList();
}

QStringList
LaunchpadService::methods() const
{
  return QStringList();
}

#include "LaunchpadService.moc"
