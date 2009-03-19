#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <KDE/KMainWindow>

class KPageView;

namespace Launchpad {
    class PageModel;
}

#include "Launchpad.h"

namespace Launchpad
{

class PageListModel;
class Page;
class PageManager;

class Launcher : public KMainWindow
{
  Q_OBJECT

  public:
    Launcher(QWidget* parent = 0, Qt::WindowFlags flags = 0);

  private:
    KPageView* m_view;
    PageModel* m_pages;
};

}

#endif
