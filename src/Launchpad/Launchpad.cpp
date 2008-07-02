#include "Launchpad.h"
#include "LaunchpadPlugin.h"
#include "Splash.h"

#include <QTimer>
#include <QMainWindow>
#include <QTabWidget>
#include <QLabel>
#include <QDesktopWidget>
#include <QRect>
#include <QSize>
#include <QPluginLoader>
#include <QDir>

class HomePage;

Launchpad::Launchpad(int argc, char** argv)
  : QApplication(argc, argv, QApplication::GuiServer)
{
    m_launcher = new QMainWindow();

    m_splash = new Splash();
    m_splash->show();
    m_splash->showMessage("Starting up...");

    m_splash->finish(m_launcher);

    m_launcher->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    m_launcher->resize(desktop()->screenGeometry().size());

    m_tabs = new QTabWidget(m_launcher);
    m_tabs->setTabPosition(QTabWidget::South);

    m_launcher->setCentralWidget(m_tabs);

    m_splash->showMessage("Loading plugins...");

    loadPlugins();

    m_launcher->show();
}

void
Launchpad::loadPlugins()
{
  foreach(QObject *plugin, QPluginLoader::staticInstances())
    loadPlugin(plugin);
  QDir pluginDir = QDir(applicationDirPath());

  pluginDir.cd("plugins");

  foreach(QString file, pluginDir.entryList(QDir::Files)) {
    loadPlugin(pluginDir.absoluteFilePath(file));
  }
}

void
Launchpad::loadPlugin(const QString &lib)
{
  QPluginLoader loader(lib);
  QObject *plugin = loader.instance();
  if (plugin) {
    loadPlugin(plugin);
  }
}

void
Launchpad::loadPlugin(QObject *plugin)
{
  LaunchpadPlugin *iLaunchpad = qobject_cast<LaunchpadPlugin *>(plugin);
  if (iLaunchpad) {
    QStringList pages = iLaunchpad->pages();
    foreach(QString page, pages)
      m_tabs->addTab(iLaunchpad->requestPage(page),page);
  }
}
