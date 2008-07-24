#ifndef LAUNCHPAD_H
#define LAUNCHPAD_H

#include <QApplication>
#include <QHash>

class QMainWindow;
class QTabWidget;
class QStackedWidget;
class QListView;
class QDockWidget;
class QModelIndex;

class Splash;
class LaunchpadPage;
class PluginManager;
class ServiceManager;
class PageListModel;

class Launchpad : public QApplication
{

  Q_OBJECT

  public:
    Launchpad(int argc, char** argv);
    void addPage(LaunchpadPage* page);

  private slots:
    void switchPage(const QModelIndex &index);
    void updatePageBarDirection(Qt::DockWidgetArea area);

  private:
    Splash* m_splash;
    QMainWindow* m_launcher;
    QStackedWidget* m_pages;
    QDockWidget* m_pageBar;
    QListView* m_pageChooser;
    PageListModel* m_pageList;
    PluginManager* plugins;
};

#endif
