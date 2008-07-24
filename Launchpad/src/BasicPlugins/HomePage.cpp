#include "HomePage.h"

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QGraphicsView>

HomePage::HomePage()
  : LaunchpadPage()
{
  setName("Dashboard");
}

void
HomePage::init()
{
  m_scene = new QGraphicsScene();
  m_scene->addText("Test");
  m_view = new QGraphicsView(m_scene);
  m_view->show();
  setWidget(m_view);
}

#include "HomePage.moc"

Q_EXPORT_PLUGIN2(homepage, HomePage)
