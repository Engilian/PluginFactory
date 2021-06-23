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
    pfactory/private_factory/icreator_factory_plugin_loader.h \
    pfactory/private_factory/ipfactory_plugin_controller.h \
    pfactory/private_factory/object_creator.h \
    pfactory/private_factory/pfactory_interface_private.h \
    pfactory/private_factory/pfactory_plugin_controller_private.h \
    pfactory/private_factory/pfactory_policy.h \
    pfactory/private_factory/pfactory_template_interface_private.h \
    pfactory/private_factory/pfactory_template_plug_creator_private.h \
    pfactory/private_factory/psys/iplugin.h \
    pfactory/private_factory/psys/isub_plugin.h \
    pfactory/private_factory/psys/loader/iplugin_loader.h \
    pfactory/private_factory/psys/loader/plugin_loader.h \
    pfactory/private_factory/psys/loader/plugin_loader_private.h \
    pfactory/private_factory/psys/plugin_data.h \
    pfactory/private_factory/sub_plugin_creator.h \
    pfactory/private_factory/template_plugin.h


SOURCES += \
    pfactory/private_factory/icreator_factory_plugin_loader.cpp \
    pfactory/private_factory/ipfactory_plugin_controller.cpp \
    pfactory/private_factory/pfactory_interface_private.cpp \
    pfactory/private_factory/pfactory_plugin_controller_private.cpp \
    pfactory/private_factory/psys/iplugin.cpp \
    pfactory/private_factory/psys/isub_plugin.cpp \
    pfactory/private_factory/psys/loader/iplugin_loader.cpp \
    pfactory/private_factory/psys/loader/plugin_loader.cpp \
    pfactory/private_factory/psys/loader/plugin_loader_private.cpp \
    pfactory/private_factory/psys/plugin_data.cpp \
    pfactory/private_factory/sub_plugin_creator.cpp \
    pfactory/private_factory/template_plugin.cpp

DISTFILES += \
    pf/Factory \
    pf/Plugin \
    pf/PluginData \
    pf/TemplatePlugin
