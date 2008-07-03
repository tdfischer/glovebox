#ifndef GPSSERVICE_H
#define GPSSERVICE_H

#include <LaunchpadService.h>

class GPSService : public LaunchpadService, QObject
{
  public:
    GPSService(int argc, char **argv);
}

#endif
