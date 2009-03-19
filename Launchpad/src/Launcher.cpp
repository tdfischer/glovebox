#include "Launcher.h"

#include <KDE/KDialog>
#include <KDE/KPageView>
#include <KDE/KPluginLoader>
#include <KDE/KPluginFactory>
#include <KDE/KServiceTypeTrader>
#include <KDE/KService>

#include "Page.h"
#include "PageModel.h"

#include <KDE/KDebug>

Launcher::Launcher(QWidget* parent, Qt::WindowFlags flags)
  : KMainWindow(parent, flags)
{
    resize(600, 480);
    m_view = new KPageView(this);
    m_pages = new PageModel(m_view);
    m_view->setModel(m_pages);
    KService::List offers = KServiceTypeTrader::self()->query("Launchpad/Page");
    kDebug() << "Found" << offers.size() << "offers:" << offers;
    foreach(KSharedPtr<KService> s, offers) {
        Page* p = s->createInstance<Page>();
        if (p) {
            kWarning() << "Error creating page";
        } else {
            kDebug() << "Added page" << p->name();
            m_pages->addPage(p);
        }
    }
    KService home("/opt/Glovebox/share/kde4/services/launchpad-page-cluster.desktop");
    KPluginFactory* factory = KPluginLoader(home).factory();
    Page* p = factory->create<Page>(this);
    p->init();
    m_pages->addPage(p);
    m_view->setFaceType(KPageView::Tabbed);
    setCentralWidget(m_view);
}

#include "Launcher.moc"
