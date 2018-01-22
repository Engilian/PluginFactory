#include "test_plugin.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkAccessManager>

TestPluginFactoryPlugin::TestPluginFactoryPlugin(QObject *parent) :
    QObject(parent),
    pf::FactoryPlugin()
{


    regCreator<QObject, QObject>( psys::SubPluginInfo
    { "QObject", "QObject", "QObject class" } );

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

QList<psys::SubPluginInfo> TestPluginFactoryPlugin::subPluginInfoList() const
{
    auto result = FactoryPlugin::subPluginInfoList ();

    // Added error interface ( for tests )
    result << psys::SubPluginInfo { "error_creator", "QObject", "" };

    return result;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(TestPluginFactoryPlugin, TestPluginFactoryPlugin)
#endif // QT_VERSION < 0x050000
