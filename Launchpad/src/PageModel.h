#ifndef PAGEMODEL_H
#define PAGEMODEL_H

#include <KDE/KPageModel>

#include "Launchpad.h"

namespace Launchpad
{

    class Page;

class PageModel : public KPageModel
{
    Q_OBJECT
    public:
        PageModel(QObject* parent = 0);
        
        QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
        QModelIndex parent(const QModelIndex &index) const;
        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        
        void addPage(Page* page);
    private:
        QList<Page*> m_pages;
};

}

#endif
