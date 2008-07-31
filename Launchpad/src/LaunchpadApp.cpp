/**
 * Copyright (C) 2008 Trever Fischer <wm161@wm161.net>
 *
 * This file is part of Glovebox.
 *
 *  Glovebox is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Glovebox is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Glovebox.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "LaunchpadApp.h"

#include "LaunchpadPage.h"
#include "PluginManager.h"
#include "Splash.h"
#include "PageListModel.h"
#include "PageListDelegate.h"
#include "Launcher.h"

#include <QTimer>
#include <QMainWindow>
#include <QLabel>
#include <QDesktopWidget>
#include <QRect>
#include <QSize>
#include <QPluginLoader>
#include <QDir>
#include <QStackedWidget>
#include <QListView>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QSizePolicy>

#include <QDebug>

LaunchpadApp::LaunchpadApp(int argc, char** argv)
  : QApplication(argc, argv, QApplication::GuiServer)
{
    setApplicationName("Glovebox");

    m_splash = new Splash();
    m_splash->show();
    m_splash->showMessage("Starting up");

    m_launcher = new Launcher();

    m_splash->finish(m_launcher);
    
    m_splash->showMessage("Building plugin loaders");
    PluginManager::instance();
    ServiceManager::instance();

    m_splash->showMessage("Loading plugins");

    PluginManager::instance()->loadPlugins();

    m_launcher->show();
}

#include "LaunchpadApp.moc"
