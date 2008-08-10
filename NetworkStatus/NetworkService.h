#ifndef NETWORKSERVICE_H
#define NETWORKSERVICE_H

#include <LaunchpadService.h>
#include <QStringList>

class QDBusInterface;

class NetworkService : public LaunchpadService {

  Q_OBJECT
  Q_INTERFACES(Launchpad::LaunchpadService)

  public:
    NetworkService(QObject* parent = 0);
    void start();
    void stop();

  private slots:
    void stateChanged(uint);
    void updateDevices();

  private:
    QDBusInterface* m_dbus;
};

#endif
