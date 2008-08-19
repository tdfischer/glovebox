#ifndef DASHWIDGET_H
#define DASHWIDGET_H

#include <QGraphicsWidget>
#include <Launchpad.h>

namespace Launchpad
{

class DashWidget : public QGraphicsWidget {

  Q_OBJECT

  Q_PROPERTY(QString name READ name WRITE setName);

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

  private:
    QString m_name;
    //WidgetHandle* m_handle;
};

}

Q_DECLARE_INTERFACE(Launchpad::DashWidget, "net.wm161.Glovebox.DashWidget/1.0")
#endif
