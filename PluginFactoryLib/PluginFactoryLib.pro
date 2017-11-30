#######################################
#                                     #
#      Plugin factory library         #
#     author engilian@gmail.com       #
#                                     #
#######################################

QT          -= gui

TARGET      = pFactory
TEMPLATE    = lib
CONFIG      += staticlib
CONFIG      += c++11

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
        plugin_factory_lib.cpp \
    pfactory/plugin/ifactory_plugin.cpp \
    pfactory/plugin/isub_plugin.cpp \
    pfactory/plugin/loader/ifactory_plugin_loader.cpp \
    pfactory/plugin/loader/factory_plugin_loader.cpp \
    pfactory/plugin/loader/private/factory_plugin_loader_private.cpp \
    pfactory/factory/plugin/iobject_creator.cpp

HEADERS += \
        plugin_factory_lib.h \
    pfactory/plugin/ifactory_plugin.h \
    pfactory/plugin/isub_plugin.h \
    pfactory/plugin/loader/ifactory_plugin_loader.h \
    pfactory/plugin/loader/factory_plugin_loader.h \
    pfactory/plugin/loader/private/factory_plugin_loader_private.h \
    pfactory/factory/plugin/iobject_creator.h
