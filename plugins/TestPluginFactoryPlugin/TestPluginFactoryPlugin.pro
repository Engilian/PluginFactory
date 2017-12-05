#-------------------------------------------------
#
# Project created by QtCreator 2017-12-05T15:20:01
#
#-------------------------------------------------

QT       += core gui

TARGET = TestPluginFactoryPlugin
TEMPLATE = lib
CONFIG += plugin

DESTDIR = ../../build/plug

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        test_plugin_factory_plugin.cpp

HEADERS += \
        test_plugin_factory_plugin.h

DISTFILES += TestPluginFactoryPlugin.json

# Plugin factory library
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../build/lib/ -lpFactory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../build/lib/ -lpFactory
else:unix: LIBS += -L$$OUT_PWD/../../build/lib/ -lpFactory

INCLUDEPATH += $$PWD/../../PluginFactoryLib
DEPENDPATH += $$PWD/../../PluginFactoryLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../build/lib/libpFactory.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../build/lib/libpFactory.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../build/lib/pFactory.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../build/lib/pFactory.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../build/lib/libpFactory.a
