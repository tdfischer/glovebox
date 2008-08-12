#ifndef GSOUNDLOADER_H
#define GSOUNDLOADER_H

#include <phonon/phonon>
#include "Glovebox.h"

namespace Glovebox
{

class GSoundLoader {
  public:
    GSoundLoader();
    ~GSoundLoader();
    
    Phonon::MediaSource getSound(const QString &name);
    
    static GSoundLoader* global() {
      static GSoundLoader* instance = 0;
      if (instance == 0)
        instance = new GSoundLoader();
      return instance;
    }
    
  private:
    Phonon::MediaSource findSound(const QString &name, const QString &theme = "default");
};

}

#endif
