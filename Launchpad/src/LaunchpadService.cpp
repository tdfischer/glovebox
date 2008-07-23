#include "LaunchpadService.h"

LaunchpadService::LaunchpadService(QObject* parent)
  : QObject(parent),
    data()
{
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

void
LaunchpadService::setRunning(const bool running)
{
  m_running = running;
}

QVariant
LaunchpadService::call(const QString &method, const QList<QVariant> &arguments)
{
  return QVariant();
}

QVariant
LaunchpadService::getData(const QString &key) const
{
  return QVariant();
}

void
LaunchpadService::setData(const QString &key, const QVariant &newData)
{
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
