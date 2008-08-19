#ifndef SIGNALWIDGET_H
#define SIGNALWIDGET_H

#include <QWidget>

class SignalWidget : public QWidget {
  Q_OBJECT
  
  Q_PROPERTY(int strength READ strength WRITE setStrength USER true)
  Q_PROPERTY(int maxStrength READ maxStrength WRITE setMaxStrength)
  
  public:
    SignalWidget(QWidget* parent = 0);
    void paintEvent(QPaintEvent* event);
    
    void setStrength(int);
    int strength() const;
    
    void setMaxStrength(int);
    int maxStrength() const;
    
    QSize sizeHint();
    
  private:
    int m_strength;
    int m_max;
};

#endif
