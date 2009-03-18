#include "Launcher.h"

#include <QStackedWidget>
#include <QDockWidget>
#include <QtDebug>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QSplitter>

#include <KDE/KDialog>

#include <QtGui/QGraphicsView>
#include <Plasma/Corona>
#include <Plasma/View>
#include <Plasma/Applet>
#include <Plasma/Containment>

#include "LaunchpadApp.h"
#include "PageListModel.h"
#include "PluginManager.h"
#include "PageListDelegate.h"
#include "Page.h"
#include "PageManager.h"

Launcher::Launcher(QWidget* parent, Qt::WindowFlags flags)
  : KMainWindow(parent, flags)
{
    QSplitter* splitter = new QSplitter(Qt::Vertical, this);
    //resize(600, 480);
    m_corona = new Plasma::Corona(this);
    Plasma::Containment* c = m_corona->addContainment(QString());
    c->init();
    c->setFormFactor(Plasma::Planar);
    c->updateConstraints(Plasma::StartupCompletedConstraint);
    c->flushPendingConstraintsEvents();
    Plasma::Applet* clock = Plasma::Applet::load("analog-clock", c->id()+1);
    c->addApplet(clock, QPointF(KDialog::spacingHint(), KDialog::spacingHint()), true);
    c->resize(600,480);
    
    m_view = new Plasma::View(c, splitter);
    m_view->resize(600,480);
    
    c = m_corona->addContainment("panel");
    c->init();
    c->setLocation(Plasma::BottomEdge);
    c->updateConstraints(Plasma::StartupCompletedConstraint);
    c->flushPendingConstraintsEvents();
    
    m_panel = new Plasma::View(c, splitter);

    splitter->addWidget(m_view);
    splitter->addWidget(m_panel);
    setCentralWidget(splitter);
  /*m_pager = new PageManager(this);
  //resize(qApp->desktop()->screenGeometry().size());
  resize(600,480);
  m_pages = new QStackedWidget(this);
  //m_pageBar = new QDockWidget(this);
  //m_pageChooser = new QListView(m_pageBar);
  m_pageChooser = new QListView(this);
  //setCentralWidget(m_pages);
  
  QSplitter* split = new QSplitter(this);
  split->addWidget(m_pageChooser);
  split->addWidget(m_pages);
  split->setCollapsible(0, true);
  split->setCollapsible(1, false);
  split->setHandleWidth(25);
  setCentralWidget(split);

  //m_pageBar->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
  //m_pageBar->setWindowTitle(tr("Pages"));
  //m_pageBar->setWidget(m_pageChooser);
  //addDockWidget(Qt::LeftDockWidgetArea, m_pageBar);

  m_pageChooser->setResizeMode(QListView::Adjust);
  m_pageChooser->setMovement(QListView::Snap);
  m_pageChooser->setModel(m_pager->model());
  m_pageChooser->setItemDelegate(new PageListDelegate(this));
  m_pageChooser->setIconSize(QSize(64, 64));
  m_pageChooser->setViewMode(QListView::IconMode);
  m_pageChooser->setFlow(QListView::TopToBottom);
  m_pageChooser->setUniformItemSizes(true);
  m_pageChooser->setSpacing(5);
  //m_pageBar->resize(QSize(64,64));
  m_pages->resize(qApp->desktop()->screenGeometry().size());

  //connect(m_pageBar, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), this, SLOT(updatePageBarDirection(Qt::DockWidgetArea)));
  connect(m_pageChooser->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(switchPage(const QModelIndex&, const QModelIndex&)));

  connect(m_pager->model(), SIGNAL(pageAdded(Page*)), this, SLOT(pageAdded(Page*)));*/
}

/*void
Launcher::updatePageBarDirection(Qt::DockWidgetArea area)
{
  if (area == Qt::LeftDockWidgetArea || area == Qt::RightDockWidgetArea)
    m_pageChooser->setFlow(QListView::TopToBottom);
  else
    m_pageChooser->setFlow(QListView::LeftToRight);
}

void
Launcher::addPage(Page* page)
{
  m_pages->addWidget(page->widget());
}

void
Launcher::pageAdded(Page* page)
{
  m_pages->addWidget(page->widget());
  connect(page, SIGNAL(dockAdded(QDockWidget*)),this, SLOT(addDock(QDockWidget*)));
  foreach(QDockWidget* dock, page->docks()) {
    addDock(dock);
  }
}

void
Launcher::addDock(QDockWidget* widget)
{
  addDockWidget(Qt::RightDockWidgetArea, widget);
  widget->hide();
  foreach(QDockWidget* dock, m_pageChooser->selectionModel()->currentIndex().data(PageListModel::DockRole).value<QList<QDockWidget*> >()) {
    dock->show();
  }
}

void
Launcher::switchPage(const QModelIndex &index, const QModelIndex &prev)
{
  qDebug() << "Switching from page" << prev.data() << "to page" << index.data();
  foreach(QDockWidget* dock, prev.data(PageListModel::DockRole).value<QList<QDockWidget*> >()) {
    dock->hide();
  }
  
  m_pages->setCurrentWidget(index.data(PageListModel::WidgetRole).value<QWidget*>());
  foreach(QDockWidget* dock, index.data(PageListModel::DockRole).value<QList<QDockWidget*> >()) {
    dock->show();
  }
}*/

#include "Launcher.moc"
