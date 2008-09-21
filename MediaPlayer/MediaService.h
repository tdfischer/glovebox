#ifndef MEDIASERVICE_H
#define MEDIASERVICE_H

#include <Service.h>
#include <QtPlugin>
#include <QStringList>

class MediaService : public Service {

  Q_OBJECT
  Q_INTERFACES(Launchpad::Service)

  public:
    MediaService(QObject* parent = 0);
    QStringList methods() const;
    QVariant call(const QString &method, const QList<QVariant> &arguments);
    void start();
    void stop();

  private:
    void playFile(const QString &file);
    void queueFile(const QString &file);
    QStringList m_queue;
};

#endif
