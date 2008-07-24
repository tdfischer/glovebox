#include "ClockPage.h"

#include <ServiceManager.h>
#include <LaunchpadService.h>

#include <QLabel>
#include <QVariant>

ClockPage::ClockPage()
  : LaunchpadPage()
{
  setName("Clock");
}

void
ClockPage::init()
{
  QFont font;
  font.setPointSize(72);
  QLabel* label = new QLabel();
  label->setFont(font);
  label->setAlignment(Qt::AlignCenter);
  setWidget(label);
  LaunchpadService* time = ServiceManager::getService("time");
  time->connectData("Time", this);
}

void
ClockPage::dataUpdated(const QString &key, const QVariant &data)
{
  QLabel* label = qobject_cast<QLabel*>(widget());
  label->setText(data.toString());
}

#include "ClockPage.moc"

Q_EXPORT_PLUGIN2(clockpage, ClockPage)
