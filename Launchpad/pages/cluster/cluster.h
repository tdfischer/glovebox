#ifndef CLUSTER_H
#define CLUSTER_H

namespace Plasma {
    class Corona;
}

#include <Page.h>
class Cluster : public Page {
    Q_OBJECT
    public:
        Cluster(QObject* parent, const QVariantList &args);
        ~Cluster();
        void init();

    private:
        Plasma::Corona* m_corona;
};

#endif
