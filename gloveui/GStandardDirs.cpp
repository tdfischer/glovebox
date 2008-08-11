#include "GStandardDirs.h"

#include "config.h"

#include <QtCore/QFile>
#include <QtCore/QDir>

#include <QDebug>

static const char suffixes[] =
"icons\0"
"icons\0"
"\0";

static const int suffixes_indexes[] = {
  0, 6, -1
};

GStandardDirs::GStandardDirs()
{
  uint index = 0;
  while (suffixes_indexes[index] != -1) {
    addResourceType(suffixes + suffixes_indexes[index], suffixes + suffixes_indexes[index+1]);
    index+=2;
  }
  addPrefix(GLOVEBOX_DATA_DIR);
  
  QByteArray xdg_paths = qgetenv("XDG_DATA_DIRS");
  foreach(const QString xdgDir, QDir::fromNativeSeparators(QFile::decodeName(xdg_paths)).split(':'))
    addPrefix(xdgDir);
    
  QByteArray glovebox_paths = qgetenv("GLOVEBOX_DIRS");
  foreach(const QString gloveDir, QDir::fromNativeSeparators(QFile::decodeName(glovebox_paths)))
    addPrefix(gloveDir);
  
  addPrefix(".");
}

void
GStandardDirs::addResourceType(const char * type, const char * relativePath)
{
  qDebug() << "Added" << relativePath << "to" << type << "list";
  types.insert(type, relativePath);
}

void
GStandardDirs::addPrefix(const QString & prefix)
{
  qDebug() << "Added prefix" << prefix;
  prefixes.append(prefix);
}

QString
GStandardDirs::findFile(const QString &type, const QString &file)
{
  if (types.contains(type)) {
    QString suffix = types[type];
    foreach(QString prefix, prefixes) {
      if (QFile::exists(prefix+"/"+suffix+"/"+file))
        return QString(prefix+"/"+suffix+"/"+file);
    }
    return QString();
  } else {
    return QString();
  }
}
