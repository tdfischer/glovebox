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

class Launcher : public QMainWindow
{
  Q_OBJECT

  public:
    Launcher(QWidget* parent = 0);

  private slots:
    void switchPage(const QModelIndex &index);
    void updatePageBarDirection(Qt::DockWidgetArea area);
    void pageAdded(LaunchpadPage*);

  private:
    QStackedWidget* m_pages;
    QDockWidget* m_pageBar;
    QListView* m_pageChooser;
    PageListModel* m_pageList;
};

}

#endif
