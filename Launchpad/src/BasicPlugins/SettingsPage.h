#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <LaunchpadPage.h>
#include <QObject>

class QStackedWidget;
class QListWidget;

class SettingsPage : public LaunchpadPage
{
  Q_OBJECT
  Q_INTERFACES(LaunchpadPage);

  public:
    SettingsPage();
    void init();

  private:
    QStackedWidget* m_pages;
    QListWidget* m_selector;
    QWidget* m_page;
};

#endif
