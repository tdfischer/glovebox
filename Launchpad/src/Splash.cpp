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

#include "Splash.h"
#include <QPainter>
#include <QRect>

#include <QDebug>

Splash::Splash()
{
  Q_INIT_RESOURCE(splash);

  /*m_fader = new QTimeLine(500, this);
  m_fader->setCurveShape(QTimeLine::EaseOutCurve);
  connect(m_fader, SIGNAL(valueChanged(qreal)), this, SLOT(updateMsgStyle()));
  connect(m_fader, SIGNAL(finished()), this, SLOT(nextStage()));*/
  connect(this, SIGNAL(messageChanged(const QString)), this, SLOT(changeMsg(const QString)));

  setPixmap(QPixmap(":/images/splash.png"));
  m_font = QFont("Helvetica");
  m_font.setBold(true);
  m_font.setPointSize(288);
}

void
Splash::changeMsg(const QString& str)
{
  /*m_msgList.append(str);
  nextStage();
  repaint();*/
  m_msg = str;
  repaint();
}

void
Splash::updateMsgStyle()
{
  repaint();
}

void
Splash::nextStage()
{
  if (m_fader->state()==QTimeLine::NotRunning) {
    if (m_fader->direction()==QTimeLine::Backward) {
      if (m_msgList.isEmpty()) {
        m_msg = "";
      } else {
        m_fader->setDirection(QTimeLine::Forward);
        m_fader->start();
        m_msg = m_msgList.takeFirst();
      }
    } else if (!m_msgList.isEmpty()) {
      m_fader->setDirection(QTimeLine::Backward);
      m_fader->start();
    }
  }
}

void
Splash::drawContents(QPainter* painter)
{
  painter->setPen(Qt::black);
  painter->setFont(m_font);
  painter->drawPixmap(rect(),m_background);
  /*painter->setOpacity(m_fader->currentValue());

  qreal offset = rect().width();
  switch (m_fader->direction()) {
    case QTimeLine::Forward: offset -= m_fader->currentValue()*rect().width();break;
    case QTimeLine::Backward: offset -= (1/m_fader->currentValue())*rect().width();break;
  }

  painter->translate(offset,0);*/
  painter->drawText(rect(), Qt::AlignCenter, m_msg);
}

#include "Splash.moc"
