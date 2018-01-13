QT          += core
QT          -= gui

CONFIG      += c++11

TARGET      = plist
CONFIG      += console
CONFIG      -= app_bundle
DESTDIR     = bin

TEMPLATE = app

SOURCES += main.cpp

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

#   Factory
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../libs/Factory/bin/ -lFactory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../libs/Factory/bin/ -lFactory
else:unix: LIBS += -L$$OUT_PWD/../../libs/Factory/bin/ -lFactory

INCLUDEPATH += $$PWD/../../libs/Factory
DEPENDPATH += $$PWD/../../libs/Factory

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/Factory/bin/libFactory.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/Factory/bin/libFactory.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/Factory/bin/Factory.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/Factory/bin/Factory.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../libs/Factory/bin/libFactory.a

#   Plugin for factory
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../libs/FactoryPlugin/bin/ -lFactoryPlugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../libs/FactoryPlugin/bin/ -lFactoryPlugin
else:unix: LIBS += -L$$OUT_PWD/../../libs/FactoryPlugin/bin/ -lFactoryPlugin

INCLUDEPATH += $$PWD/../../libs/FactoryPlugin
DEPENDPATH += $$PWD/../../libs/FactoryPlugin

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/FactoryPlugin/bin/libFactoryPlugin.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/FactoryPlugin/bin/libFactoryPlugin.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/FactoryPlugin/bin/FactoryPlugin.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/FactoryPlugin/bin/FactoryPlugin.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../libs/FactoryPlugin/bin/libFactoryPlugin.a

#   Plugin system
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../libs/PluginSystem/bin/ -lPluginSystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../libs/PluginSystem/bin/ -lPluginSystem
else:unix: LIBS += -L$$OUT_PWD/../../libs/PluginSystem/bin/ -lPluginSystem

INCLUDEPATH += $$PWD/../../libs/PluginSystem
DEPENDPATH += $$PWD/../../libs/PluginSystem

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/PluginSystem/bin/libPluginSystem.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/PluginSystem/bin/libPluginSystem.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/PluginSystem/bin/PluginSystem.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../libs/PluginSystem/bin/PluginSystem.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../libs/PluginSystem/bin/libPluginSystem.a
