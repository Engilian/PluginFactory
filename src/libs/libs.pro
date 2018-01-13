TEMPLATE = subdirs

SUBDIRS += \
    PluginSystem \
    Factory \
    FactoryPlugin

FactoryPlugin.depends   = PluginSystem
Factory.depends         = FactoryPlugin PluginSystem

#   Installs

LIBS_INSTALL_DIR = $$OUT_PWD/../../bin/libs

psys.path       = $$LIBS_INSTALL_DIR
psys.files      = $$OUT_PWD/PluginSystem/bin/*

fplug.path      = $$LIBS_INSTALL_DIR
fplug.files     = $$OUT_PWD/FactoryPlugin/bin/*

factory.path    = $$LIBS_INSTALL_DIR
factory.files   = $$OUT_PWD/Factory/bin/*


INSTALLS += \
    psys \
    fplug \
    factory
