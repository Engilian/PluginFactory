#include "test_plugin_factory_plugin.h"


TestPluginFactoryPlugin::TestPluginFactoryPlugin(QObject *parent) :
    QObject(parent),
    pfactory::IFactoryPlugin()
{
}

TestPluginFactoryPlugin::~TestPluginFactoryPlugin()
{

}

QString TestPluginFactoryPlugin::name() const
{
    return "Test pfactory plugin";
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
    return "0.001";
}

QList<pfactory::SubPluginInfo> TestPluginFactoryPlugin::subPluginInfoList() const
{
    QList<pfactory::SubPluginInfo> result;


    return result;
}

pfactory::ISubPlugin *TestPluginFactoryPlugin::create(const QString &id) const
{

    return nullptr;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(TestPluginFactoryPlugin, TestPluginFactoryPlugin)
#endif // QT_VERSION < 0x050000
