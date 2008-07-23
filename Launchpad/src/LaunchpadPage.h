#ifndef LAUNCHPADPAGE_H
#define LAUNCHPADPAGE_H


#include <QtPlugin>

#include <QStringList>
#include <QWidget>
#include <QString>

class LaunchpadPage : public QObject
{
  Q_OBJECT
  Q_PROPERTY( QString name READ name WRITE setName );

  public:
    LaunchpadPage();
    QString name() const;
    void setName(const QString &name);
    virtual QWidget* widget();

  signals:
    void nameChanged(const QString &newName);

  private:
    QString m_name;

};

Q_DECLARE_INTERFACE(LaunchpadPage, "net.wm161.Glovebox.LaunchpadPage/1.0")

#endif
