#include "GIconLoader.h"

#include "GStandardDirs.h"
#include "GIcon.h"

#include <QtCore/QVariant>
#include <QtCore/QSettings>
#include <QtCore/QStringList>
#include <QtCore/QFile>

#include <QDebug>

GIconLoader::GIconLoader()
{
}

QIcon
GIconLoader::loadIconSet(const QString &name)
{
  qDebug() << "Searching for icons for" << name;
  QIcon ret;
  loadIcon(name, "default", ret);
  return ret;
}

void
GIconLoader::loadIcon(const QString &name, const QString &theme, QIcon &icon)
{
  GStandardDirs* dirs = GStandardDirs::global();
  QString themePath = dirs->findFile("icons",theme);
  qDebug() << "Looking for icons in" << themePath;
  QSettings themeIndex(themePath+"/index.theme", QSettings::IniFormat);
  qDebug() << "Loaded index" << themeIndex.fileName();
  QStringList directories = themeIndex.value("Icon Theme/Directories").toStringList();
  qDebug() << "Available directories:" << directories;
  QStringList extensions;
  extensions << "svg" << "png";
  bool found = false;
  foreach(const QString iconDir, directories) {
    qDebug() << "Looking in" << iconDir;
    QString iconPath = themePath+"/"+iconDir;
    QVariant size = themeIndex.value(iconDir,"Size");
    QSize iconSize(size.toInt(),size.toInt());
    foreach(const QString ext, extensions) {
      if (!found && QFile::exists(iconPath + "/" + name + "." + ext)) {
        icon.addFile(iconPath + "/" + name + "." + ext, iconSize);
        found = true;
        qDebug() << "Found as" << ext << iconSize;
      }
    }
  }
  if (!found && theme != "hicolor") {
    QStringList inherit = themeIndex.value("Icon Theme/Inherits", "hicolor").toStringList();
    foreach(const QString inheritedTheme, inherit) {
      qDebug() << "Couldn't find in" << theme << "looking in" << inherit;
      loadIcon(name, inheritedTheme, icon);
    }
  }
}
