#ifndef PFACTORY_PLUGIN_CONTROLLER_PRIVATE_H
#define PFACTORY_PLUGIN_CONTROLLER_PRIVATE_H

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
    QMap<QString, QString> defaultInterfaces() const;
public:
    QList<psys::Plugin> plugins() const;
protected:
    void _loadPlugins();
private:
    PFactoryPluginController    _controller;
private:
    psys::PluginLoader         _loader;
private:
    QList<psys::Plugin>        _plugins;
    QList<psys::SubPlugin>     _creators;
};

}

#endif // PFACTORY_PLUGIN_CONTROLLER_PRIVATE_H
