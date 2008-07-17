#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "LaunchpadPlugin.h"
#include <QObject>
#include <QGraphicsView>

class QGraphicsItem;
class QGraphicsScene;

class HomePage : public QObject, public LaunchpadPlugin
{
  Q_OBJECT
  Q_INTERFACES(LaunchpadPlugin);

  public:
    HomePage();
    QString name() const;
    QStringList pages() const;
    QStringList applets() const;
    QWidget* requestPage(const QString &name);

  private:
    QGraphicsScene* m_scene;
};

#endif
