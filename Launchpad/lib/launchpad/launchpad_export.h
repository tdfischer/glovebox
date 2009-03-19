#ifndef LAUNCHPAD_EXPORT_H
#define LAUNCHPAD_EXPORT_H

#include <kdemacros.h>

#ifndef LAUNCHPAD_EXPORT
# if defined(MAKE_LAUNCHPAD_LIB)
   /* We are building this library */
#  define LAUNCHPAD_EXPORT KDE_EXPORT
# else
   /* We are using this library */
#  define LAUNCHPAD_EXPORT KDE_IMPORT
# endif
#endif

#endif

