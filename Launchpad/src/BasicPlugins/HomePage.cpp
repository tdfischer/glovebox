#include "HomePage.h"

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMessageBox>

HomePage::HomePage()
  : LaunchpadPlugin()
{
  m_scene = new QGraphicsScene();
  m_scene->addText("Test");
}

QString
HomePage::name() const
{
  return "HomePage";
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
  QGraphicsView* view = new QGraphicsView(m_scene);
  view->show();
  return view;
}

#include "HomePage.moc"

Q_EXPORT_PLUGIN2(homepage, HomePage)
