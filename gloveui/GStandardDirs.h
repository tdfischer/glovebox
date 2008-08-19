#ifndef GSTANDARDDIRS_H
#define GSTANDARDDIRS_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <QCache>

#include "Glovebox.h"

namespace Glovebox
{

class GStandardDirs {
  public:
    GStandardDirs();
    ~GStandardDirs();
    QStringList findFiles(const QString &type, const QString &file);
    QString findFile(const QString &type, const QString &file);
    static GStandardDirs* global() {
      static GStandardDirs* instance;
      if (instance == 0)
        instance = new GStandardDirs();
      return instance;
    }
    
    /**
     * @brief Adds a resource type and its relative directory
     */
    void addResourceType(const char * type, const char * relativePath);
    
    /**
     * @brief Adds a path to the list of directories to search for resources
     */
    void addPrefix(const QString &prefix);

  private:
    QStringList prefixes;
    QHash<QString, QString> types;
    QHash<QString, QStringList> cache;
};

}

#endif