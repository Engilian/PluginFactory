#ifndef TEST_PLUGIN_FACTORY_PLUGIN_H
#define TEST_PLUGIN_FACTORY_PLUGIN_H

#include <QObject>
#include <plugin_system/iplugin.h>
#include <factory_plugin/iobject_creator.h>


class TestPluginFactoryPlugin: public QObject, public psys::IPlugin
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
public:
    QList<psys::SubPluginInfo> subPluginInfoList() const;
    psys::ISubPlugin *create( const QString &id ) const;
};

#endif // TEST_PLUGIN_FACTORY_PLUGIN_H
