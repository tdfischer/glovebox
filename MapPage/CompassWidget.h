#ifndef COMPASSWIDGET_H
#define COMPASSWIDGET_H

#include <QtGui/QWidget>

class CompassWidget : public QWidget {
  Q_OBJECT
  
  Q_PROPERTY(int direction READ direction WRITE setDirection USER true)
  Q_PROPERTY(DrawOptions drawOptions READ drawOptions WRITE setDrawOptions);
  
  public:
  
    enum DrawOption {
      NoOptions = 0x0,
      Text = 0x1,
      Ticks = 0x2,
      Headings = 0x4,
      Pointer = 0x8
    };
    Q_DECLARE_FLAGS(DrawOptions, DrawOption)
  
    CompassWidget(QWidget* parent = 0);
    
    void paintEvent(QPaintEvent* event);
    void setDirection(int dir);
    int direction() const;
    QSize sizeHint();
    
    DrawOptions drawOptions() const;
    void setDrawOptions(const DrawOptions &option);
  
  private:
    int m_direction;
    DrawOptions m_flags;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(CompassWidget::DrawOptions)

#endif
