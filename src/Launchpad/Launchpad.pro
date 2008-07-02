TEMPLATE = app
TARGET = Launchpad
DEPENDPATH += . ../HomePage
LIBS = -Lplugins -lhomepage

HEADERS += Launchpad.h LaunchpadPlugin.h Splash.h
SOURCES += Launchpad.cpp main.cpp Splash.cpp
RESOURCES += splash.qrc
