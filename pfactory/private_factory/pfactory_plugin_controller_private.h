#pragma once
#include <QMap>
#include <QMultiMap>

#include "pfactory/plugin_interfaces/ipfactory_plugin_controller.h"
#include <plugin_system/loader/plugin_loader.h>

namespace pf {

///
/// \brief The PFactoryPluginControllerPrivate class
///
class PFactoryPluginControllerPrivate : public IPFactoryPluginController
{
public:
    PFactoryPluginControllerPrivate();
    ~PFactoryPluginControllerPrivate();
public:
    void setPluginsDirectory( const QString &path );
    QString pluginsDirectory() const;
public:
    QList<psys::SubPlugin> creators( const QString &interface ) const;
    psys::PluginInfo pluginInfo( psys::SubPlugin creator ) const;
public:
    QList<psys::Plugin> plugins() const;
    QList<psys::PluginInfo> pluginsInfo() const;
protected:
    void _loadPlugins();
    bool _containsSubPlugin( const QString &pluginId, const psys::SubPluginInfo &info ) const;
private:
    PFactoryPluginController    _controller;
private:
    psys::PluginLoader          _loader;
private:
    QMultiMap<QString, psys::SubPlugin> _creators;
};

}
