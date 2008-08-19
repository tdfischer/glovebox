#include "MediaService.h"

#include <phonon/phonon>
#include <QDebug>

MediaService::MediaService(QObject* parent)
  : LaunchpadService()
{
  setName("media");
}

QStringList
MediaService::methods() const
{
  return QStringList() << "play" << "pause" << "mute" << "queue";
}

QVariant
MediaService::call(const QString &method, const QList<QVariant> &args)
{
  if (method=="play")
    playFile(args.at(0).toString());
  return QVariant();
}

void
MediaService::start()
{
  //playFile("/opt/kde4/share/sounds/pop.wav");
  setRunning(true);
}

void
MediaService::stop()
{
  setRunning(false);
}

void
MediaService::playFile(const QString &file)
{
  Phonon::MediaObject *music =
    Phonon::createPlayer(Phonon::MusicCategory,
                        Phonon::MediaSource(file));
  music->play();
}

Q_EXPORT_PLUGIN2(mediaservice, MediaService)

#include "MediaService.moc"
