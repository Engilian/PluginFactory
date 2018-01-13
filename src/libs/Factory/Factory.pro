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
    pfactory/error_policy/pfactory_ignore_error_policy.cpp \
    pfactory/error_policy/pfactory_exception.cpp \
    pfactory/error_policy/pfactory_throw_exception_error_policy.cpp \
    pfactory/pfactory.cpp \
    pfactory/private_factory/pfactory_private.cpp \
    pfactory/private_factory/pfactory_template_interface_private.cpp \
    pfactory/private_factory/pfactory_template_plug_creator_private.cpp \
    pfactory/private_factory/internal_object_creator_private.cpp \
    pfactory/private_factory/pfactory_interface_private.cpp \
    pfactory/plugin_interfaces/ipfactory_plugin_controller.cpp \
    pfactory/private_factory/pfactory_plugin_controller_private.cpp \
    pfactory/private_factory/pfactory_singleton.cpp

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



#   Factory plugin library
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../FactoryPlugin/bin/ -lFactoryPlugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../FactoryPlugin/bin/ -lFactoryPlugin
else:unix: LIBS += -L$$OUT_PWD/../FactoryPlugin/bin/ -lFactoryPlugin

INCLUDEPATH += $$PWD/../FactoryPlugin
DEPENDPATH += $$PWD/../FactoryPlugin

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FactoryPlugin/bin/libFactoryPlugin.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FactoryPlugin/bin/libFactoryPlugin.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FactoryPlugin/bin/FactoryPlugin.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FactoryPlugin/bin/FactoryPlugin.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../FactoryPlugin/bin/libFactoryPlugin.a

#   Plugin system
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PluginSystem/bin/ -lPluginSystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PluginSystem/bin/ -lPluginSystem
else:unix: LIBS += -L$$OUT_PWD/../PluginSystem/bin/ -lPluginSystem

INCLUDEPATH += $$PWD/../PluginSystem
DEPENDPATH += $$PWD/../PluginSystem

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginSystem/bin/libPluginSystem.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginSystem/bin/libPluginSystem.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginSystem/bin/PluginSystem.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginSystem/bin/PluginSystem.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../PluginSystem/bin/libPluginSystem.a


