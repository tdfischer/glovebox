#include "Launcher.h"

#include <QStackedWidget>
#include <QDockWidget>
#include <QDebug>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QSizePolicy>

#include "LaunchpadApp.h"
#include "PageListModel.h"
#include "PluginManager.h"
#include "PageListDelegate.h"
#include "LaunchpadPage.h"
#include "PageManager.h"

Launcher::Launcher(QWidget* parent)
  : QMainWindow(parent, Qt::Window | Qt::FramelessWindowHint)
{
  m_pager = new PageManager(this);
  resize(qApp->desktop()->screenGeometry().size());
  m_pages = new QStackedWidget(this);
  m_pageBar = new QDockWidget(this);
  m_pageChooser = new QListView(m_pageBar);
  setCentralWidget(m_pages);

  m_pageBar->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
  m_pageBar->setWindowTitle(tr("Pages"));
  m_pageBar->setWidget(m_pageChooser);
  addDockWidget(Qt::LeftDockWidgetArea, m_pageBar);

  m_pageChooser->setResizeMode(QListView::Adjust);
  m_pageChooser->setMovement(QListView::Snap);
  m_pageChooser->setModel(m_pager->model());
  m_pageChooser->setItemDelegate(new PageListDelegate(this));
  m_pageChooser->setIconSize(QSize(64, 64));
  m_pageChooser->setViewMode(QListView::IconMode);
  m_pageChooser->setFlow(QListView::TopToBottom);
  m_pageChooser->setUniformItemSizes(true);
  m_pageChooser->setSpacing(5);
  m_pageBar->resize(QSize(64,64));
  m_pages->resize(qApp->desktop()->screenGeometry().size());

  connect(m_pageBar, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), this, SLOT(updatePageBarDirection(Qt::DockWidgetArea)));
  connect(m_pageChooser->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(switchPage(const QModelIndex&, const QModelIndex&)));

  connect(m_pager->model(), SIGNAL(pageAdded(LaunchpadPage*)), this, SLOT(pageAdded(LaunchpadPage*)));
}

void
Launcher::updatePageBarDirection(Qt::DockWidgetArea area)
{
  if (area == Qt::LeftDockWidgetArea || area == Qt::RightDockWidgetArea)
    m_pageChooser->setFlow(QListView::TopToBottom);
  else
    m_pageChooser->setFlow(QListView::LeftToRight);
}

void
Launcher::addPage(LaunchpadPage* page)
{
  m_pages->addWidget(page->widget());
}

void
Launcher::pageAdded(LaunchpadPage* page)
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
  //TODO: Hide docks from pages that aren't the top page
  addDockWidget(Qt::RightDockWidgetArea, widget);
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
}

#include "Launcher.moc"
