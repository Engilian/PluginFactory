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
    factory_plugin/factory_plugin.h \
    factory_plugin/iobject_creator.h \
    factory_plugin/object_creator.h \
    factory_plugin/sub_plugin_creator.h \
    pfactory/error_policy/pfactory_exception.h \
    pfactory/error_policy/pfactory_ignore_error_policy.h \
    pfactory/error_policy/pfactory_throw_exception_error_policy.h \
    pfactory/pfactory.h \
    pfactory/plugin_interfaces/icreator_factory_plugin_loader.h \
    pfactory/plugin_interfaces/ipfactory_plugin_controller.h \
    pfactory/private_factory/internal_object_creator_private.h \
    pfactory/private_factory/pfactory_interface_private.h \
    pfactory/private_factory/pfactory_plugin_controller_private.h \
    pfactory/private_factory/pfactory_private.h \
    pfactory/private_factory/pfactory_singleton.h \
    pfactory/private_factory/pfactory_template_interface_private.h \
    pfactory/private_factory/pfactory_template_plug_creator_private.h \
    plugin_system/iplugin.h \
    plugin_system/isub_plugin.h \
    plugin_system/loader/iplugin_loader.h \
    plugin_system/loader/plugin_loader.h \
    plugin_system/loader/private/plugin_loader_private.h \
    plugin_system/plugin_info.h \
    plugin_system/sub_plugin_info.h

SOURCES += \
    factory_plugin/factory_plugin.cpp \
    factory_plugin/sub_plugin_creator.cpp \
    pfactory/error_policy/pfactory_exception.cpp \
    pfactory/plugin_interfaces/icreator_factory_plugin_loader.cpp \
    pfactory/plugin_interfaces/ipfactory_plugin_controller.cpp \
    pfactory/private_factory/pfactory_interface_private.cpp \
    pfactory/private_factory/pfactory_plugin_controller_private.cpp \
    plugin_system/iplugin.cpp \
    plugin_system/isub_plugin.cpp \
    plugin_system/loader/iplugin_loader.cpp \
    plugin_system/loader/plugin_loader.cpp \
    plugin_system/loader/private/plugin_loader_private.cpp \
    plugin_system/plugin_info.cpp \
    plugin_system/sub_plugin_info.cpp

DISTFILES += \
    FactoryPlugin \
    PluginFactory
