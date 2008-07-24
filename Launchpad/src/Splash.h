#ifndef SPLASH_H
#define SPLASH_H

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

#include <QPainter>
#include <QPixmap>
#include <QSplashScreen>
#include <QTimeLine>

class Splash : public QSplashScreen
{
  Q_OBJECT

  public:
    Splash();
    void showMessage(const QString&);

  protected slots:
    void updateMsgStyle();
    void nextStage();

  protected:
    virtual void drawContents(QPainter*);

    QPixmap m_background;
    QStringList m_msgList;
    QString m_msg;
    QFont m_font;
    QTimeLine* m_fader;
};

#endif
