QT          += testlib
QT          -= gui

TARGET      = tst_createobjects
CONFIG      += console
CONFIG      -= app_bundle
TEMPLATE    = app
CONFIG      += c++11


DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000


SOURCES += \
        tst_createobjects.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

include(../pfactory.pri)
