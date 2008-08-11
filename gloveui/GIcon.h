#ifndef GICON_H
#define GICON_H

#include <QIcon>
#include "Glovebox.h"

namespace Glovebox {

class GIcon : public QIcon {
  public:
    GIcon(const QString &iconName);
};

}

#endif
