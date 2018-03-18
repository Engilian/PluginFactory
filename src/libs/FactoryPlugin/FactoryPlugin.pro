QT          -= gui

TARGET      = FactoryPlugin
TEMPLATE    = lib
CONFIG      += staticlib
CONFIG      += c++11
DESTDIR     = bin

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000


HEADERS += \
    factory_plugin/iobject_creator.h \
    factory_plugin/object_creator.h \
    factory_plugin/factory_plugin.h \
    factory_plugin/sub_plugin_creator.h

SOURCES += \
    factory_plugin/factory_plugin.cpp \
    factory_plugin/sub_plugin_creator.cpp

include(../psys.pri)
