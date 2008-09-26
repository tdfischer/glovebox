#ifndef DATEWIDGET_H
#define DATEWIDGET_H

#include "DashWidget.h"
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <Service.h>
#include <ServiceManager.h>

class DateWidget : public DashWidget {

  Q_OBJECT
  
  Q_INTERFACES(Launchpad::DashWidget)
  
  public:
    DateWidget(QGraphicsItem* parent = 0);
    void init();
    QRectF boundingRect() const;
    
  public slots:
    void dataUpdated(const QString &key, const QVariant &data);
    
  private:
    Service* timeService;
    QGraphicsTextItem* m_date;
};

#endif
