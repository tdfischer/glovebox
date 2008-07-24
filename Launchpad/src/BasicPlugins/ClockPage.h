#ifndef CLOCKPAGE_H
#define CLOCKPAGE_H

#include <LaunchpadPage.h>

class ClockPage : public LaunchpadPage
{
  Q_OBJECT
  Q_INTERFACES(LaunchpadPage);

  public:
    ClockPage();
    void init();

  private slots:
    void dataUpdated(const QString &key, const QVariant &data);
};

#endif
