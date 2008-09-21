#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QMainWindow>
#include <QModelIndex>
#include <QStackedWidget>
#include <QDockWidget>
#include <QListView>

#include "Launchpad.h"

namespace Launchpad
{

class PageListModel;
class Page;
class PageManager;

class Launcher : public QMainWindow
{
  Q_OBJECT

  public:
    Launcher(QWidget* parent = 0);
    void addPage(Page* page);

  private slots:
    void switchPage(const QModelIndex &index, const QModelIndex &prev);
    void updatePageBarDirection(Qt::DockWidgetArea area);
    void pageAdded(Page*);
    void addDock(QDockWidget*);

  private:
    QStackedWidget* m_pages;
    QDockWidget* m_pageBar;
    QListView* m_pageChooser;
    PageManager* m_pager;
};

}

#endif
