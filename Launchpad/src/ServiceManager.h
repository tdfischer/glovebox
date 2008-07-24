#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <QMap>
#include <QString>
#include "LaunchpadService.h"

//class PluginManager;

class ServiceManager
{

  friend class PluginManager;

  public:
    static ServiceManager *instance() {
      if (m_instance == 0)
        m_instance = new ServiceManager();
      return (m_instance);
    }

    ~ServiceManager() {
      m_instance = 0;
    }

    //bool loadService(const QString &name);
    void startService(const QString &name);
    void stopService(const QString &name);

    static LaunchpadService* getService(const QString &name);

  protected:
    LaunchpadService* findService(const QString &name) const;
    void add(LaunchpadService* service);

  private:
    ServiceManager();
    static ServiceManager *m_instance;
    QMap<QString, LaunchpadService*> serviceList;
};

#endif
