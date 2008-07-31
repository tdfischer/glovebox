#include "PageManager.h"
#include "Launcher.h"
#include "PluginManager.h"
#include "LaunchpadPage.h"
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
  LaunchpadPage* iPage = qobject_cast<LaunchpadPage*>(plugin);
  if (iPage) {
    qDebug() << "Found launchpad page plugin" << iPage->name();
    addPage(iPage);
  }
}

void
PageManager::addPage(LaunchpadPage* page)
{
  m_pageModel->addPage(page);
}

void
PageManager::removePage(LaunchpadPage* page)
{
  //TODO
}

PageListModel*
PageManager::model() const
{
  return m_pageModel;
}

#include "PageManager.moc"
