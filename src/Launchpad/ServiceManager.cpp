#include "ServiceManager.h"

ServiceManager::ServiceManager()
  : serviceList()
{
}

void
ServiceManager::add(LaunchpadService* service)
{
  serviceList.append(service);
  service->start();
}
