#include "ServiceManager.h"
#include "InvalidService.h"

ServiceManager *ServiceManager::m_instance = 0;

ServiceManager::ServiceManager()
  : serviceList()
{
}

void
ServiceManager::add(LaunchpadService* service)
{
  serviceList.insert(service->name(),service);
  service->start();
}

LaunchpadService*
ServiceManager::getService(const QString& name)
{
  ServiceManager* sm = ServiceManager::instance();
  return sm->findService(name);
}

LaunchpadService*
ServiceManager::findService(const QString& name) const
{
  if (serviceList[name]==0)
    return new InvalidService();
  else
    return serviceList[name];
}