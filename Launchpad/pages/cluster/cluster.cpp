#include <cluster.h>

#include <KDE/KPluginFactory>
#include <KDE/KIcon>

#include <KDE/Plasma/Containment>
#include <KDE/Plasma/Corona>
#include <KDE/Plasma/View>

#include <Page.h>
#include <QtGui/QLabel>

G_EXPORT_LAUNCHPAD_PAGE(cluster, Cluster)

Cluster::Cluster(QObject* parent, const QVariantList &args)
    : Page(parent, args)
{
    setName("Cluster");
    setIcon(KIcon("start-here"));
}

Cluster::~Cluster()
{
}

void
Cluster::init()
{
    m_corona = new Plasma::Corona(this);
    Plasma::Containment* containment = m_corona->addContainment("desktop");
    Plasma::View* view = new Plasma::View(containment);
    setWidget(view);
}

#include "cluster.moc"
