TEMPLATE = lib
CONFIG += plugin
TARGET = $$qtLibraryTarget(testpage)
INCLUDEPATH += ../Launchpad/
DESTDIR = ../Launchpad/plugins

HEADERS += TestPage.h
SOURCES += TestPage.cpp
