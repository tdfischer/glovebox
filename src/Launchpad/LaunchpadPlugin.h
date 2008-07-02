#ifndef LAUNCHPADPLUGIN_H
#define LAUNCHPADPLUGIN_H


#include <QtPlugin>

#include <QStringList>
#include <QWidget>
#include <QString>

class LaunchpadPlugin
{
  public:
    virtual ~LaunchpadPlugin() {}

    virtual QStringList pages() const = 0;
    virtual QStringList applets() const = 0;
    virtual QWidget* requestPage(const QString &name) = 0;
};

Q_DECLARE_INTERFACE(LaunchpadPlugin, "net.wm161.CarComputer.LaunchpadPlugin/1.0")

#endif
