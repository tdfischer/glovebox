#include "LaunchpadPage.h"

#include <QLabel>
#include <QWidget>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIcon>

LaunchpadPage::LaunchpadPage()
{
}

QWidget*
LaunchpadPage::widget()
{
  QWidget* panel = new QWidget();
  QWidget* text = new QWidget();
  QVBoxLayout* textLayout = new QVBoxLayout;
  QHBoxLayout* iconLayout = new QHBoxLayout;

  text->setLayout(textLayout);
  panel->setLayout(iconLayout);


  QLabel* iconView = new QLabel(panel);
  QPixmap icon("/opt/Glovebox/share/icons/help-hint.png");
  iconView->setPixmap(icon);

  iconLayout->addWidget(iconView);
  iconLayout->addWidget(text);

  QLabel* header = new QLabel(tr("Unable to display page"), text);
  QLabel* message = new QLabel(tr("There was an error loading the requested plugin."), text);
  header->setAlignment(Qt::AlignHCenter);
  message->setAlignment(Qt::AlignHCenter);

  QFont bigFont;
  bigFont.setBold(true);
  header->setFont(bigFont);

  textLayout->addStretch();
  textLayout->addWidget(header);
  textLayout->addWidget(message);
  textLayout->addStretch();

  header->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
  message->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

  message->setWordWrap(true);

  return panel;
}

void
LaunchpadPage::setName(const QString &name)
{
  m_name = QString(name);
  emit nameChanged(name);
}

QString
LaunchpadPage::name() const
{
  return m_name;
}

#include "LaunchpadPage.moc"
