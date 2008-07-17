#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include "LaunchpadPlugin.h"
#include <QObject>
#include <QTabWidget>

class SettingsPage : public LaunchpadPlugin
{
  Q_OBJECT
  Q_INTERFACES(LaunchpadPlugin);

  public:
    SettingsPage();
    QString name() const;
    QStringList pages() const;
    QStringList applets() const;
    QWidget* requestPage(const QString &name);

  private:
    QTabWidget* m_page;
};

#endif
