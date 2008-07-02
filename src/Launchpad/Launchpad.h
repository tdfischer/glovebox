#ifndef LAUNCHPAD_H
#define LAUNCHPAD_H

#include <QApplication>

class QMainWindow;
class QTabWidget;

class Splash;

class Launchpad : public QApplication
{

  Q_OBJECT

  public:
    Launchpad(int argc, char** argv);
    void addPage(QWidget* page);
    void loadPlugin(const QString &lib);

  protected:
    void loadPlugins();
    void loadPlugin(QObject *plugin);

  private:
    Splash* m_splash;
    QMainWindow* m_launcher;
    QTabWidget* m_tabs;
};

#endif
