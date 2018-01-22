QT       += core network

TARGET      = empty_test_plugin
TEMPLATE    = lib
CONFIG      += plugin
CONFIG      += c++11
DESTDIR     = ../../../bin/plug

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    test_plugin.cpp

HEADERS += \
    test_plugin.h

DISTFILES += \
    TestPlugin.json

include(plugin.pri)
