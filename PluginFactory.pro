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
    pfactory/error_policy/pfactory_exception.h \
    pfactory/error_policy/pfactory_ignore_error_policy.h \
    pfactory/error_policy/pfactory_throw_exception_error_policy.h \
    pfactory/pfactory.h \
    pfactory/plugin/iobject_creator.h \
    pfactory/plugin/object_creator.h \
    pfactory/plugin/psys/iplugin.h \
    pfactory/plugin/psys/isub_plugin.h \
    pfactory/plugin/psys/loader/iplugin_loader.h \
    pfactory/plugin/psys/loader/plugin_loader.h \
    pfactory/plugin/psys/loader/plugin_loader_private.h \
    pfactory/plugin/psys/plugin_data.h \
    pfactory/plugin/psys/sub_plugin_info.h \
    pfactory/plugin/sub_plugin_creator.h \
    pfactory/plugin/template_plugin.h \
    pfactory/plugin_interfaces/icreator_factory_plugin_loader.h \
    pfactory/plugin_interfaces/ipfactory_plugin_controller.h \
    pfactory/private_factory/internal_object_creator_private.h \
    pfactory/private_factory/pfactory_interface_private.h \
    pfactory/private_factory/pfactory_plugin_controller_private.h \
    pfactory/private_factory/pfactory_private.h \
    pfactory/private_factory/pfactory_singleton.h \
    pfactory/private_factory/pfactory_template_interface_private.h \
    pfactory/private_factory/pfactory_template_plug_creator_private.h


SOURCES += \
    pfactory/error_policy/pfactory_exception.cpp \
    pfactory/plugin/psys/iplugin.cpp \
    pfactory/plugin/psys/isub_plugin.cpp \
    pfactory/plugin/psys/loader/iplugin_loader.cpp \
    pfactory/plugin/psys/loader/plugin_loader.cpp \
    pfactory/plugin/psys/loader/plugin_loader_private.cpp \
    pfactory/plugin/psys/plugin_data.cpp \
    pfactory/plugin/psys/sub_plugin_info.cpp \
    pfactory/plugin/sub_plugin_creator.cpp \
    pfactory/plugin/template_plugin.cpp \
    pfactory/plugin_interfaces/icreator_factory_plugin_loader.cpp \
    pfactory/plugin_interfaces/ipfactory_plugin_controller.cpp \
    pfactory/private_factory/pfactory_interface_private.cpp \
    pfactory/private_factory/pfactory_plugin_controller_private.cpp

DISTFILES += \
    pf/Factory \
    pf/Plugin \
    pf/PluginData \
    pf/TemplatePlugin
