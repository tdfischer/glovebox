#include "PageModel.h"

#include "Page.h"

#include <KDE/KDebug>

#include "modeltest.h"

PageModel::PageModel(QObject* parent)
    : KPageModel(parent)
{
    new ModelTest(this);
}

void
PageModel::addPage(Page* page)
{
    kDebug() << "Adding page:" << page->name();
    beginInsertRows(QModelIndex(), m_pages.size(), m_pages.size());
    m_pages.append(page);
    endInsertRows();
    emit dataChanged(index(m_pages.size(), 0), index(m_pages.size(), 0));
}

QModelIndex
PageModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!parent.isValid() && column == 0 && row < m_pages.size() && row>=0) {
        return createIndex(row, column);
    } else {
        return QModelIndex();
    }
}

QModelIndex
PageModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int
PageModel::rowCount(const QModelIndex &index) const
{
    if (index.isValid()) {
        return 0;
    } else {
        return m_pages.size();
    }
}

int
PageModel::columnCount(const QModelIndex &index) const
{
    return 1;
}

QVariant
PageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row()>=m_pages.size() || index.column()>1)
        return QVariant();
    Page* page = m_pages.at(index.row());
    switch(role) {
        case Qt::DisplayRole:
            return page->name();
        case Qt::DecorationRole:
            return page->icon();
        case KPageModel::HeaderRole:
            return page->header();
        case KPageModel::WidgetRole:
            return QVariant::fromValue(page->widget());
    }
    return QVariant();
}

#include "PageModel.moc"
