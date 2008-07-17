#include "SettingsPage.h"

SettingsPage::SettingsPage()
  : LaunchpadPlugin()
{
  m_page = new QTabWidget();
}

QString
SettingsPage::name() const
{
  return "Settings";
}

QStringList
SettingsPage::pages() const
{
  return QStringList() << "Settings";
}

QStringList
SettingsPage::applets() const
{
  return QStringList();
}

QWidget*
SettingsPage::requestPage(const QString &name)
{
  return m_page;
}

#include "SettingsPage.moc"

Q_EXPORT_PLUGIN2(settingspage, SettingsPage)
