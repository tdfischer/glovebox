#ifndef LAUNCHPAD_H
#define LAUNCHPAD_H

#include <QApplication>
#include "PluginManager.h"

class QMainWindow;
class QTabWidget;

class Splash;

class PluginManager;

class Launchpad : public QApplication
{

  Q_OBJECT

  public:
    Launchpad(int argc, char** argv);
    void addPage(QWidget* page, const QString &title);

  private:
    Splash* m_splash;
    QMainWindow* m_launcher;
    QTabWidget* m_tabs;
    PluginManager* plugins;
};

#endif
