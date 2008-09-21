#include "PageManager.h"
#include "Launcher.h"
#include "PluginManager.h"
#include "Page.h"
#include "PageListModel.h"
#include <QDebug>

PageManager::PageManager(QObject* parent)
  : QObject(parent),
    m_pageModel(new PageListModel)
{
  connect(PluginManager::instance(), SIGNAL(pluginLoaded(QObject*)), this, SLOT(loadPlugin(QObject*)));
}

void
PageManager::loadPlugin(QObject* plugin)
{
  Page* iPage = qobject_cast<Page*>(plugin);
  if (iPage) {
    qDebug() << "Found launchpad page plugin" << iPage->name();
    addPage(iPage);
  }
}

void
PageManager::addPage(Page* page)
{
  m_pageModel->addPage(page);
}

void
PageManager::removePage(Page* page)
{
  //TODO
}

PageListModel*
PageManager::model() const
{
  return m_pageModel;
}

#include "PageManager.moc"
