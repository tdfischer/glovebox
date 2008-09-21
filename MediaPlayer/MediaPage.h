#ifndef MEDIAPAGE_H
#define MEDIAPAGE_H

#include <Page.h>

class MediaPage : public Page {
  Q_OBJECT
  Q_INTERFACES(Launchpad::Page)
  
  public:
    MediaPage();
    void init();
  public slots:
    void dataUpdated(const QString &key, const QVariant &value);
};

#endif
