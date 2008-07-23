#include "Launchpad.h"
#include "LaunchpadPage.h"
#include "PluginManager.h"
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


Launchpad::Launchpad(int argc, char** argv)
  : QApplication(argc, argv, QApplication::GuiServer)
{
    setApplicationName("Glovebox");

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

    plugins = new PluginManager(this);

    plugins->loadPlugins();

    //Look, ma! Phonon!

    m_launcher->show();
    /*Phonon::MediaObject *mediaObject = new Phonon::MediaObject(this);
    mediaObject->setCurrentSource(Phonon::MediaSource("sounds/startup.wav"));
    Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::NotificationCategory, this);
    Phonon::Path path = Phonon::createPath(mediaObject, audioOutput);
    mediaObject->play();*/
}

void
Launchpad::addPage(LaunchpadPage* page)
{
  m_tabs->addTab(page->widget(), page->name());
}

#include "Launchpad.moc"
