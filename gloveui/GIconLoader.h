#ifndef GICONLOADER_H
#define GICONLOADER_H

#include <QIcon>
#include "Glovebox.h"

namespace Glovebox
{

class GIconLoader {
  public:
    GIconLoader();
    ~GIconLoader();
    QIcon loadIconSet(const QString &name);
    static GIconLoader* global() {
      static GIconLoader* instance = 0;
      if (instance == 0)
        instance = new GIconLoader();
      return instance;
    }
    
  private:
    void loadIcon(const QString &name, const QString &theme, QIcon &icon);
};

}

#endif
