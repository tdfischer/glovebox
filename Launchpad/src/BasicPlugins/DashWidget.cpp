#include "DashWidget.h"

#include <QPainter>

#include <QLabel>

DashWidget::DashWidget(QGraphicsItem* parent, Qt::WindowFlags wFlags)
  : QGraphicsWidget(parent, wFlags)
{
  //m_handle = new WidgetHandle(this);
}

DashWidget::~DashWidget()
{
}

void
DashWidget::init()
{
  //QLabel* lbl = new QLabel("Requested widget could not be loaded.");
}

QString
DashWidget::name() const
{
  return m_name;
}

void
DashWidget::setName(const QString &name)
{
  m_name = name;
}

void
DashWidget::setAutoDrawBackground(bool t)
{
  m_autoDrawBackground = t;
}

bool
DashWidget::autoDrawBackground() const
{
  return m_autoDrawBackground;
}

void
DashWidget::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  drawBackground(painter, option, widget);
}

void
DashWidget::drawBackground(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  painter->drawRect(boundingRect());
}

#include "DashWidget.moc"
