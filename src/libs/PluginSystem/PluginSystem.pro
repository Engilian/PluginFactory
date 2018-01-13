QT          -= gui

TARGET      = PluginSystem
TEMPLATE    = lib
CONFIG      += staticlib
CONFIG      += c++11
DESTDIR     = bin

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

HEADERS += \
    plugin_system/isub_plugin.h \
    plugin_system/iplugin.h \
    plugin_system/loader/iplugin_loader.h \
    plugin_system/loader/plugin_loader.h \
    plugin_system/loader/private/plugin_loader_private.h

SOURCES += \
    plugin_system/isub_plugin.cpp \
    plugin_system/iplugin.cpp \
    plugin_system/loader/private/plugin_loader_private.cpp \
    plugin_system/loader/plugin_loader.cpp \
    plugin_system/loader/iplugin_loader.cpp
