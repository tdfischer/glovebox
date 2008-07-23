#include "SettingsPage.h"

#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QStackedWidget>
#include <QListWidget>
#include <QIcon>
#include <QWidget>
#include <QLabel>

SettingsPage::SettingsPage()
{
  setName("Settings");
}

QWidget*
SettingsPage::widget()
{
  m_page = new QWidget();
  QHBoxLayout* layout = new QHBoxLayout(m_page);
  m_page->setLayout(layout);

  m_selector = new QListWidget(m_page);
  QListWidgetItem* testItem = new QListWidgetItem(QIcon("/opt/Glovebox/share/icons/help-hint.png"), "Hints", m_selector);
  m_selector->setViewMode(QListView::IconMode);

  m_pages = new QStackedWidget(m_page);

  layout->addWidget(m_selector);
  layout->addWidget(m_pages);
  return m_page;
}

#include "SettingsPage.moc"

Q_EXPORT_PLUGIN2(settingspage, SettingsPage)
