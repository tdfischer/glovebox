#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include "DashWidget.h"
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <Service.h>
#include <ServiceManager.h>

class ClockWidget : public DashWidget {

  Q_OBJECT
  
  Q_INTERFACES(Launchpad::DashWidget)
  
  public:
    ClockWidget(QGraphicsItem* parent = 0);
    void init();
    QRectF boundingRect() const;
    
  public slots:
    void dataUpdated(const QString &key, const QVariant &data);
    
  private:
    Service* timeService;
    QGraphicsEllipseItem* m_clock;
    QGraphicsPolygonItem* m_minutes;
    QGraphicsPolygonItem* m_seconds;
    QGraphicsPolygonItem* m_hours;
};

#endif
