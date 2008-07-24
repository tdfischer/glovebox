#ifndef TIMESERVICE_H
#define TIMESERVICE_H

#include <LaunchpadService.h>

#include <QObject>
#include <QtPlugin>

class QStringList;
class QTimer;

class TimeService : public LaunchpadService
{
  Q_OBJECT
  Q_INTERFACES(LaunchpadService)

  public:
    TimeService();
    QStringList sources() const;
    void start();
    void stop();
    void requestUpdate(const QString &key);

  protected slots:
    void timeUpdate();

  private:
    QTimer* m_timer;
};

#endif
