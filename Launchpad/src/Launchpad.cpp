#include "Launchpad.h"

#include "LaunchpadPage.h"
#include "PluginManager.h"
#include "Splash.h"
#include "PageListModel.h"
#include "PageListDelegate.h"

#include <QTimer>
#include <QMainWindow>
#include <QLabel>
#include <QDesktopWidget>
#include <QRect>
#include <QSize>
#include <QPluginLoader>
#include <QDir>
#include <QStackedWidget>
#include <QListView>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QSizePolicy>

#include <QDebug>


Launchpad::Launchpad(int argc, char** argv)
  : QApplication(argc, argv, QApplication::GuiServer),
    m_pageList(new PageListModel)
{
    setApplicationName("Glovebox");


    m_launcher = new QMainWindow();

    m_splash = new Splash();
    m_splash->show();
    m_splash->showMessage("Starting up...");

    m_splash->finish(m_launcher);

    m_launcher->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    m_launcher->resize(desktop()->screenGeometry().size());

   /* m_tabs = new QTabWidget(m_launcher);
    m_tabs->setTabPosition(QTabWidget::South);

    m_launcher->setCentralWidget(m_tabs);*/

    m_pages = new QStackedWidget(m_launcher);
    m_launcher->setCentralWidget(m_pages);

    m_pageBar = new QDockWidget(m_launcher);
    connect(m_pageBar, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), this, SLOT(updatePageBarDirection(Qt::DockWidgetArea)));

    QVBoxLayout* barLayout = new QVBoxLayout(m_pageBar);
    m_pageChooser = new QListView(m_pageBar);
    connect(m_pageChooser, SIGNAL(clicked(const QModelIndex&)), this, SLOT(switchPage(const QModelIndex&)));

    m_launcher->addDockWidget(Qt::LeftDockWidgetArea, m_pageBar);
    m_pageBar->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
    m_pageBar->setWindowTitle(tr("Pages"));
    m_pageBar->setWidget(m_pageChooser);

    //m_pageChooser->setViewMode(QListView::IconMode);
    m_pageChooser->setResizeMode(QListView::Adjust);
    //m_pageChooser->setUniformItemSizes(true);
    //m_pageChooser->setGridSize(QSize(100,200));
    m_pageChooser->setMovement(QListView::Snap);
    m_pageChooser->setModel(m_pageList);
    //m_pageChooser->setIconSize(QSize(32,32));
    m_pageChooser->setItemDelegate(new PageListDelegate(this));
    m_pageChooser->setSpacing(5);

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
  page->init();
  m_pages->addWidget(page->widget());
  m_pageList->addPage(page);
}

void
Launchpad::updatePageBarDirection(Qt::DockWidgetArea area)
{
  if (area == Qt::LeftDockWidgetArea || area == Qt::RightDockWidgetArea)
    m_pageChooser->setFlow(QListView::TopToBottom);
  else
    m_pageChooser->setFlow(QListView::LeftToRight);
}

void
Launchpad::switchPage(const QModelIndex &index)
{
  qDebug() << "Switching to page" << index.data();
  m_pages->setCurrentWidget(index.data(PageListModel::WidgetRole).value<QWidget*>());
}

#include "Launchpad.moc"
