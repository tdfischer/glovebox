#ifndef PAGELISTMODEL_H
#define PAGELISTMODEL_H

#include <QAbstractListModel>
#include <QIcon>

class LaunchpadPage;

class PageListModel : public QAbstractListModel
{

  Q_OBJECT


  public:
    enum UserRoles { WidgetRole = Qt::UserRole };
    PageListModel(QObject* parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

    void addPage(LaunchpadPage* page);

  private:
    QList<LaunchpadPage*> m_pages;
};

#endif
