#include "Launcher.h"

#include <QStackedWidget>
#include <QDockWidget>
#include <QDebug>
#include <QDesktopWidget>
#include <QHBoxLayout>

#include "LaunchpadApp.h"
#include "PageListModel.h"
#include "PluginManager.h"
#include "PageListDelegate.h"
#include "LaunchpadPage.h"

Launcher::Launcher(QWidget* parent)
  : QMainWindow(parent, Qt::Window | Qt::FramelessWindowHint)
{
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
  m_pageChooser->setModel(PluginManager::instance()->pageModel());
  m_pageChooser->setItemDelegate(new PageListDelegate(this));
  m_pageChooser->setSpacing(5);

  connect(m_pageBar, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), this, SLOT(updatePageBarDirection(Qt::DockWidgetArea)));
  connect(m_pageChooser, SIGNAL(clicked(const QModelIndex&)), this, SLOT(switchPage(const QModelIndex&)));

  connect(PluginManager::instance()->pageModel(), SIGNAL(pageAdded(LaunchpadPage*)), this, SLOT(pageAdded(LaunchpadPage*)));
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
Launcher::pageAdded(LaunchpadPage* page)
{
  m_pages->addWidget(page->widget());
}

void
Launcher::switchPage(const QModelIndex &index)
{
  qDebug() << "Switching to page" << index.data();
  m_pages->setCurrentWidget(index.data(PageListModel::WidgetRole).value<QWidget*>());
}

#include "Launcher.moc"