#include "CompassWidget.h"

#include <QPainter>

#include <QTimer>
#include <QtDebug>

CompassWidget::CompassWidget(QWidget* parent)
  : QWidget(parent),
    m_direction(0)
{
  setDrawOptions(Text | Ticks | Headings);
}

void
CompassWidget::setDrawOptions(const DrawOptions &option)
{
  m_flags = option;
}

CompassWidget::DrawOptions
CompassWidget::drawOptions() const
{
  return m_flags;
}

void
CompassWidget::setDirection(int dir)
{
  m_direction = dir;
  update();
}

int
CompassWidget::direction() const
{
  return m_direction;
}

QSize
CompassWidget::sizeHint()
{
  return QSize(200, 200);
}

void
CompassWidget::paintEvent(QPaintEvent* event)
{

  static const QPoint arrowPoints[4] = {
    QPoint(0,-25),
    QPoint(-25,-50),
    QPoint(0, 50),
    QPoint(25, -50)
  };
  
  int side = qMin(width(), height());
  
  QPainter painter(this);
  QFont headingFont;
  headingFont.setWeight(QFont::Bold);
  headingFont.setPixelSize(25);
  QFontMetrics fm(headingFont);
  painter.setFont(headingFont);
  
  painter.setRenderHint(QPainter::Antialiasing);
  painter.translate(width() / 2, height() / 2);
  painter.scale(side / 200.0, side / 200.0);
  
  painter.setPen(palette().color(QPalette::Dark));
  painter.setBrush(palette().button());
  painter.drawEllipse(QPoint(0,0), 100-fm.height(), 100-fm.height());
  
  if (m_flags & Ticks) {
    painter.save();
    QLine bigTick(0,-70, 0, -90);
    QLine smallTick(0, -75, 0, -85);
    QLine tinyTick(0, -75, 0, -80);
    for(int i=0;i<4;i++) {
      painter.drawLine(bigTick);
      painter.rotate(30);
      painter.drawLine(smallTick);
      painter.rotate(30);
      painter.drawLine(smallTick);
      painter.rotate(30);
    }
    painter.restore();
    
    painter.save();
    for(int i=0;i<360;i+=5) {
      painter.rotate(5);
      painter.drawLine(tinyTick);
    }
    painter.restore();
  }
  
  if (m_flags & Headings) {
    painter.save();
    painter.drawText(-fm.width('N')/2, -100+fm.height(), "N");
    painter.rotate(90);
    painter.drawText(-fm.width('E')/2, -100+fm.height(), "E");
    painter.rotate(90);
    painter.drawText(-fm.width('S')/2, -100+fm.height(), "S");
    painter.rotate(90);
    painter.drawText(-fm.width('W')/2, -100+fm.height(), "W");
    painter.restore();
  }
  
  painter.save();
  painter.rotate(90-m_direction);
  painter.setPen(palette().color(QPalette::Dark));
  painter.setBrush(palette().light());
  if (m_flags & Pointer) {
    QLine pointerLine(0, 0, 0, 100);
    painter.drawLine(pointerLine);
  }
  painter.drawPolygon(arrowPoints, 4);
  painter.restore();
  
  if (m_flags & Text) {
    painter.drawText(-fontMetrics().width(QString("%1").arg(m_direction))/2,fontMetrics().height()/2, QString("%1").arg(m_direction));
  }
}

#include "CompassWidget.moc"
