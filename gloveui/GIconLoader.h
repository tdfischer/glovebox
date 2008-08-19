#ifndef GICONLOADER_H
#define GICONLOADER_H

#include <QIcon>
#include "Glovebox.h"

#include <QHash>
#include <QString>

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
    
    void buildCache(const QString &theme = "default");
    
  private:
    typedef struct CachedIcon {
      QSize size;
      QString path;
    } CachedIcon;
    void loadIcon(const QString &name, const QString &theme, QIcon &icon);
    QHash<QString, QHash<int, QString> > iconPathCache;
};

}

#endif
