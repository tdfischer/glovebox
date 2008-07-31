#ifndef PAGEMANAGER_H
#define PAGEMANAGER_H

#include <QObject>
#include <QList>

#include "Launchpad.h"

namespace Launchpad
{

class LaunchpadPage;
class Launcher;
class PageListModel;

/**
 * @brief Manages the widgets associated with Launchpad pages
 *
 * The PageManager is meant to be constructed from within the
 * LaunchpadApp startup sequence.
 */

class PageManager : public QObject {

  Q_OBJECT

  public:
    PageManager(QObject* parent = 0);
    void addPage(LaunchpadPage* page);
    void removePage(LaunchpadPage* page);
    PageListModel* model() const;

  private slots:
    void loadPlugin(QObject* plugin);

  private:
    PageListModel* m_pageModel;
};

}

#endif
