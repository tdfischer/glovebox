#ifndef GNOTIFY_H
#define GNOTIFY_H

#include <QObject>
#include "Glovebox.h"

namespace Glovebox
{

class GNotify : public QObject {
  Q_OBJECT

  public:
    static GNotify* global() {
      static GNotify* instance = 0;
      if (instance == 0)
        instance = new GNotify();
      return instance;
    }

    void sound(const QString &name);

  private:
    GNotify();
};
}

#endif
