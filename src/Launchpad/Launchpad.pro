TEMPLATE = app
TARGET = Launchpad
DEPENDPATH += . ../HomePage
LIBS = -Lplugins -lhomepage
QT += phonon

HEADERS += Launchpad.h LaunchpadPlugin.h Splash.h LaunchpadService.h ServiceManager.h PluginManager.h
SOURCES += Launchpad.cpp main.cpp Splash.cpp LaunchpadService.cpp ServiceManager.cpp PluginManager.cpp
RESOURCES += splash.qrc
