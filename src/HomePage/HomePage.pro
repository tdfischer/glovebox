TEMPLATE = lib
CONFIG += plugin static
TARGET = $$qtLibraryTarget(homepage)
INCLUDEPATH += ../Launchpad/
DESTDIR = ../Launchpad/plugins

HEADERS += HomePage.h
SOURCES += HomePage.cpp
