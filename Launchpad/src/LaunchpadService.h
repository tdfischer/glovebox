#ifndef LAUNCHPADSERVICE_H
#define LAUNCHPADSERVICE_H

#include <QtPlugin>
#include <QObject>
#include <QHash>
#include <QVariant>

class QStringList;

class LaunchpadService : public QObject
{

  Q_OBJECT
  Q_PROPERTY(bool valid READ isValid);
  Q_PROPERTY(QString name READ name WRITE setName);
  Q_PROPERTY(bool running READ running WRITE setRunning);

  public:
    LaunchpadService();

    QString name() const;

    virtual QStringList sources() const;
    QVariant query(const QString &key) const;

    virtual void requestUpdate(const QString &key) = 0;

    void connectData(const QString &key, QObject* endpoint) const;

    virtual QStringList methods() const;
    virtual QVariant call(const QString &method, const QList<QVariant> &arguments);

    virtual void start();
    virtual void stop();
    bool running();

    bool isValid();

  signals:
    void dataUpdated(const QString &key, const QVariant &data);

  protected:
    void setData(const QString &key, const QVariant &data);
    void setRunning(const bool running);
    void setName(const QString &name);

  private:
    QHash<QString, QVariant> data;
    bool m_running;
    QString m_name;
};

Q_DECLARE_INTERFACE(LaunchpadService, "net.wm161.Glovebox.LaunchpadService/1.0")

#endif
