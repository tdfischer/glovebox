#include "HomePage.h"

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QGraphicsView>

HomePage::HomePage()
{
  setName("Dashboard");
}

QWidget*
HomePage::widget()
{
  m_scene = new QGraphicsScene();
  m_scene->addText("Test");
  m_view = new QGraphicsView(m_scene);
  m_view->show();
  return m_view;
}

#include "HomePage.moc"

Q_EXPORT_PLUGIN2(homepage, HomePage)
