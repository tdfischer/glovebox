#include "Splash.h"
#include <QPainter>
#include <QRect>

#include <QDebug>

Splash::Splash()
{
  Q_INIT_RESOURCE(splash);

  m_fader = new QTimeLine(1500, this);
  m_fader->setCurveShape(QTimeLine::EaseOutCurve);
  connect(m_fader, SIGNAL(valueChanged(qreal)), this, SLOT(updateMsgStyle()));
  connect(m_fader, SIGNAL(finished()), this, SLOT(nextStage()));

  setPixmap(QPixmap(":/images/splash.png"));
  m_font = QFont("Helvetica");
  m_font.setBold(true);
  m_font.setPointSize(288);
}

void
Splash::showMessage(const QString& str)
{
  m_msgList.append(str);
  nextStage();
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
  painter->setOpacity(m_fader->currentValue());

  qreal offset = rect().width();
  switch (m_fader->direction()) {
    case QTimeLine::Forward: offset -= m_fader->currentValue()*rect().width();break;
    case QTimeLine::Backward: offset -= (1/m_fader->currentValue())*rect().width();break;
  }

  painter->translate(offset,0);
  painter->drawText(rect(), Qt::AlignCenter, m_msg);
}
