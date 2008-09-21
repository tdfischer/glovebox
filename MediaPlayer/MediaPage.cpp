#include "MediaPage.h"

#include <GIcon.h>

#include <QHBoxLayout>
#include <QLabel>

MediaPage::MediaPage()
  : Page()
{
  setName("Media");
  setIcon(GIcon("applications-multimedia"));
}

void
MediaPage::init()
{
  QWidget* frame = new QWidget();
  frame->setLayout(new QHBoxLayout(frame));
  QLabel* nowPlaying = new QLabel(frame);
  setWidget(frame);
}

#include "MediaPage.moc"

Q_EXPORT_PLUGIN2(mediapage, MediaPage);
