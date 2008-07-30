#ifndef LAUNCHPADSERVICE_H
#define LAUNCHPADSERVICE_H

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
#include <QObject>
#include <QHash>
#include <QVariant>

class QStringList;

#include "Launchpad.h"

namespace Launchpad
{

class LaunchpadService : public QObject
{

  Q_OBJECT
  Q_PROPERTY(bool valid READ isValid);
  Q_PROPERTY(QString name READ name WRITE setName);
  Q_PROPERTY(bool running READ running WRITE setRunning);

  public:
    LaunchpadService();

    QString name() const;

    virtual QStringList sources() const;
    QVariant query(const QString &key) const;

    virtual void requestUpdate(const QString &key);

    void connectData(const QString &key, QObject* endpoint);

    virtual QStringList methods() const;
    virtual QVariant call(const QString &method, const QList<QVariant> &arguments);

    virtual void start();
    virtual void stop();
    bool running();

    bool isValid();

  signals:
    void dataUpdated(const QString &key, const QVariant &data);

  protected:
    void setData(const QString &key, const QVariant &data);
    void setRunning(const bool running);
    void setName(const QString &name);

  private:
    QHash<QString, QVariant> data;
    bool m_running;
    QString m_name;
};

}

Q_DECLARE_INTERFACE(Launchpad::LaunchpadService, "net.wm161.Glovebox.LaunchpadService/1.0")

#endif
