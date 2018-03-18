#ifndef TST_PLUGIN_FOR_PFACTORY_H
#define TST_PLUGIN_FOR_PFACTORY_H

#include <QObject>
#include <plugin_system/iplugin.h>
#include <factory_plugin/factory_plugin.h>

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
    QString name() const override;
    QString logo() const override;
    QString briefInfo() const override;
    QString detailedInfo() const override;
    QString author() const override;
    QString version() const override;
public:
    QList<psys::SubPluginInfo> subPluginInfoList() const override;
};

#endif // TST_PLUGIN_FOR_PFACTORY_H
