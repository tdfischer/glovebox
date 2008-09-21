#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include "DashWidget.h"
#include <QGraphicsTextItem>
#include <Service.h>
#include <ServiceManager.h>

class ClockWidget : public DashWidget {

  Q_OBJECT
  
  Q_INTERFACES(Launchpad::DashWidget)
  
  public:
    ClockWidget(QGraphicsItem* parent = 0);
    void init();
    
  public slots:
    void dataUpdated(const QString &key, const QVariant &data);
    
  private:
    Service* timeService;
    QGraphicsTextItem* m_label;
};

#endif
