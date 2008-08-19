#ifndef MEDIAPAGE_H
#define MEDIAPAGE_H

#include <LaunchpadPage.h>

class MediaPage : public LaunchpadPage {
  Q_OBJECT
  Q_INTERFACES(Launchpad::LaunchpadPage)
  
  public:
    MediaPage();
    void init();
  public slots:
    void dataUpdated(const QString &key, const QVariant &value);
};

#endif
