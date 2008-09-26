#ifndef DASHWIDGET_H
#define DASHWIDGET_H

#include <QGraphicsWidget>
#include <Launchpad.h>

namespace Launchpad
{

class DashWidget : public QGraphicsWidget {

  Q_OBJECT

  Q_PROPERTY(QString name READ name WRITE setName);
  Q_PROPERTY(bool autoDrawBackground READ autoDrawBackground WRITE setAutoDrawBackground);

  public:
    DashWidget(QGraphicsItem* parent = 0, Qt::WindowFlags wFlags = 0);
    virtual ~DashWidget();

    /**
     * @brief Widgets should implement this method to perform any UI setup
     */
    virtual void init();
    
    /**
     * @brief Gets the widget's name
     */
    QString name() const;
    
    /**
     * @brief Sets the widget's name
     */
    void setName(const QString &name);
    
    /**
     * @brief If true, the background will automatically be drawn.
     */
     void setAutoDrawBackground(bool t);
     
    /**
     * @brief Returns if the background is set to automatically be drawn.
     */
     bool autoDrawBackground() const;
     
    /**
     * @brief This implementation provides the background drawing. Reimplement to have total control.
     */
     void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
     
    /**
     * @brief Call this to draw the default background, using QGraphicsItem::boundingRect() as the rectangle.
     */
     void drawBackground(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);

  private:
    QString m_name;
    bool m_autoDrawBackground;
};

}

Q_DECLARE_INTERFACE(Launchpad::DashWidget, "net.wm161.Glovebox.DashWidget/1.0")
#endif
