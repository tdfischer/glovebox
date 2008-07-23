#ifndef LAUNCHPADSERVICE_H
#define LAUNCHPADSERVICE_H

#include <QtPlugin>
#include <QObject>

class QStringList;
class QList;
class QVariant;
class QHash;

class LaunchpadService : public QObject
{

  Q_OBJECT
  Q_PROPERTY(bool running READ running WRITE setRunning);

  public:
    LaunchpadService(QObject* parent = 0);

    virtual QString name() const = 0;

    virtual QStringList sources() const;
    QVariant query(const QString &key) const;
    void connectData(const QString &key, QObject* endpoint) const;

    virtual QStringList methods() const;
    virtual QVariant call(const QString &method, const QList<QVariant> &arguments);

    virtual void start();
    virtual void stop();
    bool running();

  signals:
    void dataUpdated(const QString &key, const QVariant &data);

  protected:
    virtual void setData(const QString &key, const QVariant &data);
    virtual QVariant getData(const QString &key) const;
    void setRunning(const bool running);

  private:
    QHash<QString, QVariant> data;
    bool m_running;
};

Q_DECLARE_INTERFACE(LaunchpadService, "net.wm161.Glovebox.LaunchpadService/1.0")

#endif
