QT          += core
QT          -= gui

TARGET      = plist
CONFIG      += console
CONFIG      -= app_bundle
CONFIG      += c++11
DESTDIR     = ../../../bin

TEMPLATE = app

SOURCES += main.cpp

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../pfactory.pri)
