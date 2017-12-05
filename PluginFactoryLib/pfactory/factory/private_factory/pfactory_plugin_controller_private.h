#ifndef PFACTORY_PLUGIN_CONTROLLER_PRIVATE_H
#define PFACTORY_PLUGIN_CONTROLLER_PRIVATE_H

#include "pfactory/factory/plugin_interfaces/ipfactory_plugin_controller.h"
#include "pfactory/plugin/loader/factory_plugin_loader.h"

namespace pfactory {

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
    QList<SubPlugin> creators( const QString &interface ) const;
    QMap<QString, QString> defaultInterfaces() const;
public:
    QList<FactoryPlugin> plugins() const;
protected:
    void _loadPlugins();
private:
    PFactoryPluginController    _controller;
private:
    FactoryPluginLoader         _loader;
private:
    QList<FactoryPlugin>        _plugins;
    QList<SubPlugin>            _creators;
};

}

#endif // PFACTORY_PLUGIN_CONTROLLER_PRIVATE_H
