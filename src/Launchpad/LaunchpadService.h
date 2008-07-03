#ifndef LAUNCHPADSERVICE_H
#define LAUNCHPADSERVICE_H

#include <QtPlugin>
#include <QObject>
#include <QStringList>
#include <QList>
#include <QVariant>
#include <QHash>

class LaunchpadService : public QObject
{

  Q_OBJECT

  public:
    LaunchpadService(QObject* parent = 0);
    //virtual ~LaunchpadService();
    virtual QStringList sources() const;
    virtual QStringList methods() const;
    virtual QVariant call(const QString &method, const QList<QVariant> &arguments) = 0;
    QVariant query(const QString &key) const;
    void connectData(const QString &key, QObject* endpoint) const;
    virtual void start() {};
    virtual void stop() {};

  signals:
    void dataUpdated(const QString &key, const QVariant &data);

  protected:
    virtual void setData(const QString &key, const QVariant &data);
    virtual void getData(const QString &key) const = 0;

  private:
    QHash<QString, QVariant> data;
};

Q_DECLARE_INTERFACE(LaunchpadService, "net.wm161.Glovebox.LaunchpadService/1.0")

#endif
