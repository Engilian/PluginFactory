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
DESTDIR     = ../build/lib

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
        plugin_factory_lib.cpp \
    pfactory/plugin/ifactory_plugin.cpp \
    pfactory/plugin/isub_plugin.cpp \
    pfactory/plugin/loader/ifactory_plugin_loader.cpp \
    pfactory/plugin/loader/factory_plugin_loader.cpp \
    pfactory/plugin/loader/private/factory_plugin_loader_private.cpp \
    pfactory/factory/plugin/iobject_creator.cpp \
    pfactory/factory/plugin_interfaces/icreator_factory_plugin_loader.cpp \
    pfactory/factory/error_policy/pfactory_ignore_error_policy.cpp \
    pfactory/factory/error_policy/pfactory_exception.cpp \
    pfactory/factory/error_policy/pfactory_throw_exception_error_policy.cpp \
    pfactory/factory/pfactory.cpp \
    pfactory/factory/private_factory/pfactory_private.cpp \
    pfactory/factory/private_factory/pfactory_template_interface_private.cpp \
    pfactory/factory/private_factory/pfactory_template_plug_creator_private.cpp \
    pfactory/factory/private_factory/internal_object_creator_private.cpp \
    pfactory/factory/private_factory/pfactory_interface_private.cpp \
    pfactory/factory/plugin_interfaces/ipfactory_plugin_controller.cpp \
    pfactory/factory/private_factory/pfactory_plugin_controller_private.cpp

HEADERS += \
        plugin_factory_lib.h \
    pfactory/plugin/ifactory_plugin.h \
    pfactory/plugin/isub_plugin.h \
    pfactory/plugin/loader/ifactory_plugin_loader.h \
    pfactory/plugin/loader/factory_plugin_loader.h \
    pfactory/plugin/loader/private/factory_plugin_loader_private.h \
    pfactory/factory/plugin/iobject_creator.h \
    pfactory/factory/plugin_interfaces/icreator_factory_plugin_loader.h \
    pfactory/factory/error_policy/pfactory_ignore_error_policy.h \
    pfactory/factory/error_policy/pfactory_exception.h \
    pfactory/factory/error_policy/pfactory_throw_exception_error_policy.h \
    pfactory/factory/pfactory.h \
    pfactory/factory/private_factory/pfactory_private.h \
    pfactory/factory/private_factory/pfactory_macro.h \
    pfactory/factory/private_factory/pfactory_template_interface_private.h \
    pfactory/factory/private_factory/pfactory_template_plug_creator_private.h \
    pfactory/factory/private_factory/internal_object_creator_private.h \
    pfactory/factory/private_factory/pfactory_interface_private.h \
    pfactory/factory/plugin_interfaces/ipfactory_plugin_controller.h \
    pfactory/factory/private_factory/pfactory_plugin_controller_private.h \
    pfactory/factory/private_factory/pfactory_singlenton.h
