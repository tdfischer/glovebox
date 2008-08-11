#include "GIcon.h"

#include "GIconLoader.h"

GIcon::GIcon(const QString &iconName)
  : QIcon(GIconLoader::global()->loadIconSet(iconName))
{
}
