TEMPLATE = lib
CONFIG += plugin
TARGET = $$qtLibraryTarget(service_gps)
INCLUDEPATH += ../Launchpad/
DESTDIR = ../Launchpad/plugins

HEADERS = GPSService.h
SOURCES = GPSService.cpp
