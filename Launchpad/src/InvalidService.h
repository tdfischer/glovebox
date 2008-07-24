#include "LaunchpadService.h"

class InvalidService : public LaunchpadService
{
  bool isValid() {return false;}
  void requestUpdate(const QString &key) {}
  void start() { stop(); }
};
