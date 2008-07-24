#ifndef LAUNCHPADPAGE_H
#define LAUNCHPADPAGE_H


#include <QtPlugin>

#include <QStringList>
#include <QWidget>
#include <QString>
#include <QIcon>

/**
 * A page for use in the Launchpad interface
 *
 * LaunchpadPagess are one of the key components to Launchpad.
 */

class LaunchpadPage : public QObject
{
  Q_OBJECT
  Q_PROPERTY( QString name READ name WRITE setName );
  Q_PROPERTY( QIcon icon READ icon WRITE setIcon );

  public:
    LaunchpadPage();
    QString name() const;
    void setName(const QString &name);
    void setIcon(const QIcon &icon);
    void setWidget(QWidget* widget);

    QIcon icon() const;

    /**
     * 
     */
    virtual void init() = 0;

    /**
     * Returns the QWidget that this page is made of.
     */
    QWidget* widget() const;

  signals:
    /**
     * Used by Launchpad to know when to update the page's title.
     */
    void nameChanged(LaunchpadPage* page, const QString &newName);

    /**
     * Used by Launchpad to know when to update the page's icon.
     */
    void iconChanged(LaunchpadPage* page, const QIcon &icon);

    /**
     * Emitted when the page's widget is changed
     */
    void widgetChanged(LaunchpadPage* page, QWidget* widget);

  private:
    QString m_name;
    QIcon m_icon;
    QWidget* m_widget;

};

Q_DECLARE_INTERFACE(LaunchpadPage, "net.wm161.Glovebox.LaunchpadPage/1.0")

#endif
