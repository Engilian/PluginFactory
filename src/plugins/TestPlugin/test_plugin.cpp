#include "test_plugin.h"


TestPluginFactoryPlugin::TestPluginFactoryPlugin(QObject *parent) :
    QObject(parent),
    psys::IPlugin()
{
}

TestPluginFactoryPlugin::~TestPluginFactoryPlugin()
{

}

QString TestPluginFactoryPlugin::name() const
{
    return "Test PFactory plugin";
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
    QList<psys::SubPluginInfo> result;

    result << psys::SubPluginInfo {
              "Emty 1",
              "Empty interface 1",
              "Test empty interface" };

    result << psys::SubPluginInfo {
              "Emty 2",
              "Empty interface 2",
              "Test empty interface" };

    result << psys::SubPluginInfo {
              "Emty 3",
              "Empty interface 3",
              "Test empty interface" };

    result << psys::SubPluginInfo {
              "Emty 4",
              "Empty interface 4",
              "Test empty interface" };

    return result;
}

psys::ISubPlugin *TestPluginFactoryPlugin::create(const QString &id) const
{
    Q_UNUSED( id );

    return nullptr;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(TestPluginFactoryPlugin, TestPluginFactoryPlugin)
#endif // QT_VERSION < 0x050000
