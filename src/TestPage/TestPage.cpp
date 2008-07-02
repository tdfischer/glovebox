#include "TestPage.h"
#include <Launchpad.h>

#include <QLabel>

QStringList
TestPage::pages() const
{
  return QStringList() << "Test" << "Test2";
}

QStringList
TestPage::applets() const
{
  return QStringList();
}

QWidget*
TestPage::requestPage(const QString &name)
{
  QLabel* lbl = new QLabel(name);
  return lbl;
}

Q_EXPORT_PLUGIN2(testpage, TestPage)
