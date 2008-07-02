#include "HomePage.h"
#include <Launchpad.h>

#include <QGraphicsScene>
#include <QGraphicsTextItem>

HomePage::HomePage()
  : LaunchpadPlugin()
{
  m_scene = new QGraphicsScene();
  m_test = new QGraphicsTextItem("Test!");
  m_scene->addItem(m_test);
}

QStringList
HomePage::pages() const
{
  return QStringList() << "Dashboard";
}

QStringList
HomePage::applets() const
{
  return QStringList();
}

QWidget*
HomePage::requestPage(const QString &name)
{
  Q_UNUSED(name);
  QGraphicsView* view = new QGraphicsView(m_scene);
  return view;
}

Q_EXPORT_PLUGIN2(homepage, HomePage)
