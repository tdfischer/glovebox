#ifndef GPSSERVICE_H
#define GPSSERVICE_H

#include <QCoreApplication>
#include <QDbus>

class GPSService : public QCoreApplication
{
  public:
    GPSService(int argc, char **argv);
}

#endif
