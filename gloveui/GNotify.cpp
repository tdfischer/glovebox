#include "GNotify.h"

#include "GSoundLoader.h"

#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>

GNotify::GNotify()
  : QObject()
{
}

void
GNotify::sound(const QString &name)
{
  Phonon::MediaObject* player = new Phonon::MediaObject();
  player->setCurrentSource(GSoundLoader::global()->getSound(name));
  Phonon::AudioOutput* out = new Phonon::AudioOutput(Phonon::NotificationCategory, this);
  Phonon::createPath(player, out);
  player->play();
}

void
GNotify::speak(const QString &text)
{
  
}

#include "GNotify.moc"
