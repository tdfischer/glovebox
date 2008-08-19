#include "GStandardDirs.h"

#include "config.h"

#include <QtCore/QFile>
#include <QtCore/QDir>

#include <stdlib.h>

#include <QDebug>

static const char suffixes[] =
"icons\0"
"icons\0"
"sounds\0"
"sounds\0"
"\0";

static const int suffixes_indexes[] = {
  0, 6, 12, 19, -1
};

GStandardDirs::GStandardDirs()
{
  uint index = 0;
  while (suffixes_indexes[index] != -1) {
    addResourceType(suffixes + suffixes_indexes[index], suffixes + suffixes_indexes[index+1]);
    index+=2;
  }
  addPrefix(GLOVEBOX_DATA_DIR);
  
  QStringList xdg_paths = QString(QFile::decodeName(getenv("XDG_DATA_DIRS"))).split(':');
  foreach(const QString xdgDir, xdg_paths)
    addPrefix(QDir::fromNativeSeparators(xdgDir));
    
  QStringList glovebox_paths = QString(QFile::decodeName(getenv("GLOVEBOX_DIRS"))).split(':');
  foreach(const QString gloveDir, glovebox_paths)
    addPrefix(QDir::fromNativeSeparators(gloveDir));
  
  addPrefix(".");

  addPrefix(QDir::homePath()+"/.glovebox/share");
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
  QStringList files = findFiles(type,file);
  if (files.empty())
    return QString();
  return findFiles(type, file).at(0);
}

QStringList
GStandardDirs::findFiles(const QString &type, const QString &file)
{
  if (cache.contains(type+"/"+file))
    return cache[type+"/"+file];
  QStringList ret;
  if (types.contains(type)) {
    QString suffix = types[type];
    foreach(const QString prefix, prefixes) {
      QString path = prefix+"/"+suffix+"/"+file;
      if (QFile::exists(path)) {
        ret.append(path);
      }
    }
    cache.insert(type+"/"+file, ret);
  }
  return ret;
}
