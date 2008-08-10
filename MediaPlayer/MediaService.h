#ifndef MEDIASERVICE_H
#define MEDIASERVICE_H

#include <LaunchpadService.h>
#include <QtPlugin>
#include <QStringList>

class MediaService : public LaunchpadService {

  Q_OBJECT
  Q_INTERFACES(Launchpad::LaunchpadService)

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
