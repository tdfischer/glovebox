#ifndef SPLASH_H
#define SPLASH_H

#include <QPainter>
#include <QPixmap>
#include <QSplashScreen>
#include <QTimeLine>

class Splash : public QSplashScreen
{
  Q_OBJECT

  public:
    Splash();
    void showMessage(const QString&);

  protected slots:
    void updateMsgStyle();
    void nextStage();

  protected:
    virtual void drawContents(QPainter*);

    QPixmap m_background;
    QStringList m_msgList;
    QString m_msg;
    QFont m_font;
    QTimeLine* m_fader;
};

#endif
