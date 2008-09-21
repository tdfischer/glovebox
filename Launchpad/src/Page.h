#ifndef LAUNCHPADPAGE_H
#define LAUNCHPADPAGE_H

/**
 * Copyright (C) 2008 Trever Fischer <wm161@wm161.net>
 *
 * This file is part of Glovebox.
 *
 *  Glovebox is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Glovebox is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Glovebox.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QtPlugin>

#include <QStringList>
#include <QWidget>
#include <QString>
#include <QIcon>
#include <QDockWidget>

#include "Launchpad.h"

namespace Launchpad
{

/**
 * A page for use in the Launchpad interface
 *
 * Pagess are one of the key components to Launchpad.
 */

class Page : public QObject
{
  Q_OBJECT
  Q_PROPERTY( QString name READ name WRITE setName );
  Q_PROPERTY( QIcon icon READ icon WRITE setIcon );

  public:
    Page();
    virtual ~Page();
    QString name() const;
    void setName(const QString &name);
    void setIcon(const QIcon &icon);
    void setWidget(QWidget* widget);

    void addDock(QDockWidget* dock);
    void removeDock(QDockWidget* dock);
    QList<QDockWidget*> docks() const;

    QIcon icon() const;

    /**
     * 
     */
    virtual void init() = 0;

    /**
     * Returns the QWidget that this page is made of.
     */
    QWidget* widget() const;

  public slots:
    void hideDocks();
    void showDocks();

  signals:
    /**
     * Used by Launchpad to know when to update the page's title.
     */
    void nameChanged(Page* page, const QString &newName);

    /**
     * Used by Launchpad to know when to update the page's icon.
     */
    void iconChanged(Page* page, const QIcon &icon);

    /**
     * Emitted when the page's widget is changed
     */
    void widgetChanged(Page* page, QWidget* widget);
    
    /**
     * Emitted when the page adds a dock
     */
    void dockAdded(QDockWidget* widget);
    
  protected:
    void hideEvent(QHideEvent* event);
    void showEvent(QShowEvent* event);

  private:
    QString m_name;
    QIcon m_icon;
    QWidget* m_widget;
    QList<QDockWidget*> m_dockWidgets;
};

}

Q_DECLARE_INTERFACE(Launchpad::Page, "net.wm161.Glovebox.Page/1.0")

#endif
