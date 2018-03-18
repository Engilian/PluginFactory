#######################################
#                                     #
#      Plugin factory library         #
#     author engilian@gmail.com       #
#                                     #
#######################################

QT          -= gui

TARGET      = Factory
TEMPLATE    = lib
CONFIG      += staticlib
CONFIG      += c++11
DESTDIR     = bin

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000


SOURCES += \
    pfactory/plugin_interfaces/icreator_factory_plugin_loader.cpp \
    pfactory/error_policy/pfactory_exception.cpp \
    pfactory/private_factory/pfactory_interface_private.cpp \
    pfactory/plugin_interfaces/ipfactory_plugin_controller.cpp \
    pfactory/private_factory/pfactory_plugin_controller_private.cpp

HEADERS += \
    pfactory/plugin_interfaces/icreator_factory_plugin_loader.h \
    pfactory/error_policy/pfactory_ignore_error_policy.h \
    pfactory/error_policy/pfactory_exception.h \
    pfactory/error_policy/pfactory_throw_exception_error_policy.h \
    pfactory/pfactory.h \
    pfactory/private_factory/pfactory_private.h \
    pfactory/private_factory/pfactory_template_interface_private.h \
    pfactory/private_factory/pfactory_template_plug_creator_private.h \
    pfactory/private_factory/internal_object_creator_private.h \
    pfactory/private_factory/pfactory_interface_private.h \
    pfactory/plugin_interfaces/ipfactory_plugin_controller.h \
    pfactory/private_factory/pfactory_plugin_controller_private.h \
    pfactory/private_factory/pfactory_singleton.h

include(../fplugin.pri)
include(../psys.pri)
