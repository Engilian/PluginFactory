QT          += core
QT          -= gui

CONFIG      += c++11

TARGET      = plist
CONFIG      += console
CONFIG      -= app_bundle
DESTDIR     = ../../build

TEMPLATE = app

SOURCES += main.cpp \
    plugin_list_controller.cpp \
    view/iconsole_controller.cpp \
    view/main_console_controller.cpp

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Plugin factory library
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../build/lib/ -lpFactory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../build/lib/ -lpFactory
else:unix: LIBS += -L$$OUT_PWD/../../build/lib/ -lpFactory

INCLUDEPATH += $$PWD/../../PluginFactoryLib
DEPENDPATH += $$PWD/../../PluginFactoryLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../build/lib/libpFactory.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../build/lib/libpFactory.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../build/lib/pFactory.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../build/lib/pFactory.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../build/lib/libpFactory.a

HEADERS += \
    plugin_list_controller.h \
    view/iconsole_controller.h \
    view/main_console_controller.h
