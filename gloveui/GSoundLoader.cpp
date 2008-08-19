#include "GSoundLoader.h"

#include "GStandardDirs.h"

#include <QtCore/QVariant>
#include <QtCore/QSettings>
#include <QtCore/QStringList>
#include <QtCore/QFile>

#include <QDebug>

GSoundLoader::GSoundLoader()
{
}

Phonon::MediaSource
GSoundLoader::getSound(const QString &name)
{
  return findSound(name);
}

Phonon::MediaSource
GSoundLoader::findSound(const QString &name, const QString &theme)
{
  GStandardDirs* dirs = GStandardDirs::global();
  QString themePath = dirs->findFile("sounds",theme);
  qDebug() << "Looking for sounds in" << themePath;
  QSettings themeIndex(themePath+"/index.theme", QSettings::IniFormat);
  qDebug() << "Loaded index" << themeIndex.fileName();
  QStringList directories = themeIndex.value("Sound Theme/Directories").toStringList();
  qDebug() << "Available directories:" << directories;
  QStringList extensions;
  extensions << "ogg" << "wav";
  bool found = false;
  QString subname = name;
  do {
    foreach(const QString soundDir, directories) {
      qDebug() << "Looking in" << soundDir;
      QString soundPath = themePath+"/"+soundDir;
      foreach(const QString ext, extensions) {
        if (!found && QFile::exists(soundPath + "/" + subname + "." + ext)) {
          qDebug() << "Found as" << ext;
          return Phonon::MediaSource(soundPath + "/" + subname + "." + ext);
        }
      }
    }
    subname = subname.section('-', 0, -2);
    qDebug() << "Shortening to" << subname;
  } while (subname.contains('-'));
  if (!found && theme != "freedesktop") {
    QStringList inherit = themeIndex.value("Sound Theme/Inherits", "freedesktop").toStringList();
    qDebug() << "Couldn't find in" << theme << "looking in" << inherit;
    foreach(const QString inheritedTheme, inherit) {
      return findSound(name, inheritedTheme);
    }
  }
  qDebug() << "Couldn't find any sound.";
}
