#ifndef GPSPAGE_H
#define GPSPAGE_H

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

#include <LaunchpadPage.h>

//Voodoo magic begins
#define PluginManager Marble::PluginManager
#include <marble/MarbleWidget.h>
#undef PluginManager
//Voodoo magic stops

class MapPage : public LaunchpadPage {

  Q_OBJECT
  Q_INTERFACES(LaunchpadPage)

  public:
    MapPage();
    void init();

  private:
    MarbleWidget* map;

};

#endif
