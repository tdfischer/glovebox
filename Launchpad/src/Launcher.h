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
class LaunchpadPage;
class PageManager;

class Launcher : public QMainWindow
{
  Q_OBJECT

  public:
    Launcher(QWidget* parent = 0);
    void addPage(LaunchpadPage* page);

  private slots:
    void switchPage(const QModelIndex &index);
    void updatePageBarDirection(Qt::DockWidgetArea area);
    void pageAdded(LaunchpadPage*);

  private:
    QStackedWidget* m_pages;
    QDockWidget* m_pageBar;
    QListView* m_pageChooser;
    PageManager* m_pager;
};

}

#endif
