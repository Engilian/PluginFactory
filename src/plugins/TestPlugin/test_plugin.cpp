#include "test_plugin.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkAccessManager>

#include <factory_plugin/object_creator.h>

QList<psys::SubPluginInfo> createCreators() {

    QList<psys::SubPluginInfo> creators;

    creators << psys::SubPluginInfo { "QObject", "QObject", "" };
    creators << psys::SubPluginInfo { "QTcpServer", "QObject", "" };
    creators << psys::SubPluginInfo { "QTcpSocket", "QObject", "" };
    creators << psys::SubPluginInfo { "QNetworkAccessManager", "QObject", "" };
    creators << psys::SubPluginInfo { "error_creator", "QObject", "" };

    return creators;
}

TestPluginFactoryPlugin::TestPluginFactoryPlugin(QObject *parent) :
    QObject(parent),
    psys::IPlugin(),
    creators ( createCreators () )
{
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
    return creators;
}

psys::ISubPlugin *TestPluginFactoryPlugin::create(const QString &id) const
{

    if ( id.compare( "QObject" ) == 0 ) {
        return new pf::ObjectCreator<QObject, QObject>( "QObject", "QObject", "" );
    }
    else if ( id.compare( "QTcpServer" ) == 0 ) {
        return new pf::ObjectCreator<QObject, QTcpServer>( "QTcpServer", "QObject", "" );
    }
    else if ( id.compare( "QTcpSocket" ) == 0 ) {
        return new pf::ObjectCreator<QObject, QTcpSocket>( "QTcpSocket", "QObject", "" );
    }
    else if ( id.compare( "QNetworkAccessManager" ) == 0 ) {
        return new pf::ObjectCreator<QObject, QNetworkAccessManager>( "QNetworkAccessManager", "QObject", "" );
    }

    return nullptr;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(TestPluginFactoryPlugin, TestPluginFactoryPlugin)
#endif // QT_VERSION < 0x050000
