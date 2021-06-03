# PluginFactory

A simple library for loading the implementation of interfaces from a dynamic library. The dynamic library uses the qt plugin format.


Example of use
==============

Headers
-------

```c++
#include <pfactory/pfactory.h>
```

Adding an internal implementation of the interface.
---------------------------------------------------
```c++
pf::Factory::instance ()->add<QObject, QWidget>( "QObject", "QWidget" );
```

Adding external interface implementations.
------------------------------------------
```c++
pf::Factory::instance ()->add<QObject>( "QObject" );
```

Set the implementation of the default interface.
------------------------------------------------
```c++
// We inform the factory of the intention to 
// create QObject implementations
pf::Factory::instance ()->add<QObject>( "QObject" );
pf::Factory::instance ()->setDefault<QObject>( "QTcpServer" );
```

Creating one heir from the interface.
-------------------------------------
```c++
// We inform the factory of the intention to 
// create QObject implementations.
pf::Factory::instance ()->add<QObject>( "QObject" );

// Create the default interface implementation.
auto *obj = pf::Factory::instance ()->create<QObject>();
```

Create a specific implementation of the interface.
--------------------------------------------------
```c++
// We inform the factory of the intention to 
// create QObject implementations
pf::Factory::instance ()->add<QObject>( "QObject" );

// Create a specific implementation of the interface.
auto *obj = pf::Factory::instance ()->create<QObject>( "QTcpServer" );
```

Create all available interface implementations.
-----------------------------------------------
```c++
// We inform the factory of the intention to 
// create QObject implementations
pf::Factory::instance ()->add<QObject>( "QObject" );

QList<QObject *> objects;
// Obtaining and enumerating all available interface implementations.
for ( auto &id: f->creatorNames<QObject>() ) {

    // Create a specific implementation.
    objects << pf::Factory::instance ()->create<QObject>( id );
}
```

Example of creating a plugin
============================
An example of implementing a plugin that creates various classes that are inherited from QObject.

Plugin pro file TestPlugin.pro
------------------------------
```qmake
QT          += core network

TARGET      = empty_test_plugin
TEMPLATE    = lib
CONFIG      += plugin
CONFIG      += c++11
DESTDIR     = ../../../bin/plug

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    test_plugin.cpp

HEADERS += \
    test_plugin.h

DISTFILES += \
    TestPlugin.json

include(plugin.pri)
```
plugins.pri
-----------

At the moment, the library connection is not very convenient. In the future it will be corrected.
```qmake

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/external/PluginFactory/release/ -lPluginFactory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/external/PluginFactory/debug/ -lPluginFactory
else:unix: LIBS += -L$$OUT_PWD/external/PluginFactory/ -lPluginFactory

INCLUDEPATH += $$PWD/external/PluginFactory
DEPENDPATH += $$PWD/external/PluginFactory

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/external/PluginFactory/release/libPluginFactory.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/external/PluginFactory/debug/libPluginFactory.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/external/PluginFactory/release/PluginFactory.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/external/PluginFactory/debug/PluginFactory.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/external/PluginFactory/libPluginFactory.a

```

Header file for the factory plugin test_plugin.h
----------------------------------

```c++
#include <QObject>
#include <FactoryPlugin>

class TestPluginFactoryPlugin: public QObject, public pf::FactoryPlugin
{
    Q_OBJECT
    Q_INTERFACES (psys::IPlugin)
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID FACTORY_PLUGIN_VALID_STRING FILE "TestPlugin.json")
#endif // QT_VERSION >= 0x050000

public:
    TestPluginFactoryPlugin(QObject *parent = 0);
    ~TestPluginFactoryPlugin();
public:
    QString name() const;
    QString logo() const;
    QString briefInfo() const;
    QString detailedInfo() const;
    QString author() const;
    QString version() const;
};
```

The plug-in implementation file for the factory test_plugin.cpp
-----------------------------------------------

```c++
#include "test_plugin.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkAccessManager>

TestPluginFactoryPlugin::TestPluginFactoryPlugin(QObject *parent) :
    QObject(parent),
    pf::FactoryPlugin()
{

    // Adding the QObject interface implementation -> QTcpServer.
    regCreator<QObject, QTcpServer>( psys::SubPluginInfo
    { "QTcpServer", "QObject", "QTcpServer class" } );

    // Adding the QObject interface implementation -> QTcpSocket.
    regCreator<QObject, QTcpSocket>( psys::SubPluginInfo
    { "QTcpSocket", "QObject", "QTcpSocket class" } );

    // Adding the QObject interface implementation -> QNetworkAccessManager.
    regCreator<QObject, QNetworkAccessManager>( psys::SubPluginInfo
    { "QNetworkAccessManager", "QObject", "QNetworkAccessManager class" } );
}

TestPluginFactoryPlugin::~TestPluginFactoryPlugin()
{

}

QString TestPluginFactoryPlugin::name() const
{
    return "PFactory plugin for unit test";
}

QString TestPluginFactoryPlugin::logo() const
{
    return "";
}

QString TestPluginFactoryPlugin::briefInfo() const
{
    return "Plug-in for testing the serviceability of the factory";
}

QString TestPluginFactoryPlugin::detailedInfo() const
{
    return "Plugin for testing the integrity of the factory. It is not"
           " recommended that this plug-in be included in the delivery of "
           "ready-made applications.";
}

QString TestPluginFactoryPlugin::author() const
{
    return "engilian@gmail.com";
}

QString TestPluginFactoryPlugin::version() const
{
    return "0.002";
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(TestPluginFactoryPlugin, TestPluginFactoryPlugin)
#endif // QT_VERSION < 0x050000

```