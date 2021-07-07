#######################################
#                                     #
#      Plugin factory library         #
#     author engilian@gmail.com       #
#                                     #
#######################################

QT          -= gui

TARGET      = PluginFactory
TEMPLATE    = lib
CONFIG      += staticlib
CONFIG      += c++11

HEADERS += \
    pfactory/pfactory.h \
    pfactory/private_factory/error_policy.h \
    pfactory/private_factory/object_creator.h \
    pfactory/private_factory/iplugin.h \
    pfactory/private_factory/plugin_controller.h \
    pfactory/private_factory/template_plugin.h


SOURCES += \
    pfactory/private_factory/iplugin.cpp \
    pfactory/private_factory/plugin_controller.cpp \
    pfactory/private_factory/template_plugin.cpp

DISTFILES += \
    pf/Factory \
    pf/Plugin \
    pf/TemplatePlugin
