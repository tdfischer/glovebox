#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "LaunchpadPlugin.h"
#include <QObject>

class TestPage : public QObject, public LaunchpadPlugin
{
  Q_OBJECT
  Q_INTERFACES(LaunchpadPlugin);

  public:
    QStringList pages() const;
    QStringList applets() const;
    QWidget* requestPage(const QString &name);

};

#endif
