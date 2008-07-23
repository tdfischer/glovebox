#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <LaunchpadPage.h>

class QGraphicsView;
class QGraphicsScene;

class HomePage : public LaunchpadPage
{
  Q_OBJECT
  Q_INTERFACES(LaunchpadPage);

  public:
    HomePage();
    QWidget* widget();

  private:
    QGraphicsScene* m_scene;
    QGraphicsView* m_view;
};

#endif
