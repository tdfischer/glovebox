#include "DashWidget.h"

#include <QLabel>

DashWidget::DashWidget(QGraphicsItem* parent, Qt::WindowFlags wFlags)
  : QGraphicsWidget(parent, wFlags)
{
  m_handle = new WidgetHandle(this);
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

#include "DashWidget.moc"
