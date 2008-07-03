#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <QList>
#include "LaunchpadService.h"

//class PluginManager;

class ServiceManager
{

  friend class PluginManager;

  public:
    ServiceManager();
    bool loadService(const QString &name);
    void startService(const QString &name);
    void stopService(const QString &name);

  protected:
    void add(LaunchpadService* service);

  private:
    QList<LaunchpadService*> serviceList;
};

#endif
