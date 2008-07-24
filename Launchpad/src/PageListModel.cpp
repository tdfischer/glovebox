#include "PageListModel.h"

#include "LaunchpadPage.h"

PageListModel::PageListModel(QObject* parent)
  : QAbstractListModel(parent),
    m_pages()
{
}

void
PageListModel::addPage(LaunchpadPage* page)
{
  m_pages.append(page);
}

int
PageListModel::rowCount(const QModelIndex &parent) const
{
  return m_pages.count();
}

QVariant
PageListModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  if (index.row() >= m_pages.size())
    return QVariant();

  if (role == Qt::DisplayRole)
    return m_pages.at(index.row())->name();
  else if (role == Qt::DecorationRole)
    return m_pages.at(index.row())->icon();
  else if (role == PageListModel::WidgetRole)
    return QVariant::fromValue(m_pages.at(index.row())->widget());
  else
    return QVariant();
}

#include "PageListModel.moc"
