#include "SignalWidget.h"

#include <QPainter>
#include <QtDebug>

SignalWidget::SignalWidget(QWidget* parent)
  : QWidget(parent),
    m_max(100),
    m_strength(0)
{
}

QSize
SignalWidget::sizeHint()
{
  return QSize(200, 100);
}

void
SignalWidget::paintEvent(QPaintEvent* event)
{
  QPainter painter(this);
  int side = qMin(width(), height());
  painter.scale(width() / 200.0, height() / 100.0);
  Q_ASSERT(m_max > 0);
  qreal value = m_strength/(qreal)m_max;
  for(int i=1;i<=5;i++) {
    if (value>i/5.0)
      painter.setBrush(palette().brush(QPalette::Highlight));
    else
      painter.setBrush(palette().brush(QPalette::Button));
    painter.drawRect(200*((i-1)/5.0), 100, 200*(1/5.0), -100*(i/5.0));
  }
}

int
SignalWidget::strength() const
{
  return m_strength;
}

int
SignalWidget::maxStrength() const
{
  return m_max;
}

void
SignalWidget::setStrength(int str)
{
  m_strength = str;
  update();
}

void
SignalWidget::setMaxStrength(int max)
{
  m_max = max;
  update();
}

#include "SignalWidget.moc"
