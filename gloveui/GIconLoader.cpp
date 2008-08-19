#include "GIconLoader.h"

#include "GStandardDirs.h"
#include "GIcon.h"

#include <QtCore/QVariant>
#include <QtCore/QSettings>
#include <QtCore/QStringList>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QSize>

#include <QtDebug>

GIconLoader::GIconLoader()
{
  buildCache();
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
GIconLoader::buildCache(const QString &theme)
{
  qDebug() << "Building icon theme cache in" << theme;
  QString themePath = GStandardDirs::global()->findFile("icons", theme);
  qDebug() << "Looking in" << themePath;
  QSettings themeIndex(themePath + "/index.theme", QSettings::IniFormat);
  QStringList directories = themeIndex.value("Icon Theme/Directories").toStringList();
  qDebug() << "Available directories:" << directories;
  QStringList extensions = QStringList() << "svg" << "png";
  foreach(const QString iconDir, directories) {
    QDir iconPath(themePath+"/"+iconDir);
    int size = themeIndex.value(iconDir+"/Size").toInt();
    QString type = themeIndex.value(iconDir+"/Type").toString();
    size = (type=="Scalable") ? -1 : size;
    foreach(QString icon, iconPath.entryList(QDir::Files)) {
      QString ext = icon.remove(icon.lastIndexOf('.'),icon.length());
      QHash<int, QString> iconCache;
      if (iconPathCache.contains(icon))
        iconCache = iconPathCache[icon];
      if (!iconCache.contains(size)) {
        iconCache.insert(size, iconPath.absoluteFilePath(icon));
        iconPathCache[icon] = iconCache;
        //qDebug() << "Found icon" << icon << "in" << theme;
      } else {
        //qDebug() << "Icon for" << icon << "already cached at size" << size;
      }
    }
  }
  if (theme != "hicolor") {
    QStringList inherits = themeIndex.value("Icon Theme/Inherits", QStringList("hicolor")).toStringList();
    foreach(const QString inheritedTheme, inherits) {
      buildCache(inheritedTheme);
    }
  }
}

void
GIconLoader::loadIcon(const QString &name, const QString &theme, QIcon &icon)
{
  if (iconPathCache.contains(name)) {
    QHash<int, QString> cache = iconPathCache[name];
    if (cache.contains(-1)) {
      icon.addFile(cache[-1]);
      return;
    }
    QHash<int, QString>::const_iterator i;
    for(i = cache.constBegin(); i != cache.constEnd(); ++i) {
      int iconSize = i.key();
      icon.addFile(i.value(), QSize(iconSize, iconSize));
      qDebug() << i.value() << "for" << name;
    }
    /*foreach(const QString iconPath, iconPathCache[name]) {
      QSize iconSize(
      icon.addFile(
    }*/
  }
}

/*void
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
}*/
