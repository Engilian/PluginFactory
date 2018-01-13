#include "pfactory_plugin_controller_private.h"
using namespace pfactory;

#include <QDir>
#include <QCoreApplication>

PFactoryPluginControllerPrivate::PFactoryPluginControllerPrivate():
    IPFactoryPluginController( "PFactoryPluginControllerPrivate",
                               "Default loaded controller" )
{

    _loadPlugins ();
}

PFactoryPluginControllerPrivate::~PFactoryPluginControllerPrivate()
{

}

void PFactoryPluginControllerPrivate::setPluginsDirectory(const QString &path)
{
    if ( _controller ) _controller->setPluginsDirectory ( path );
    else {

        _loader.setPluginDirPath ( path );

        _plugins.clear ();
        _creators.clear ();

        _loadPlugins ();
    }
}

QString PFactoryPluginControllerPrivate::pluginsDirectory() const
{
    if ( _controller ) return _controller->pluginsDirectory ();

    return _loader.pluginDirPath ();
}

QList<psys::SubPlugin> PFactoryPluginControllerPrivate::creators(const QString &interface) const
{
    if ( _controller ) return _controller->creators ( interface );

    QList<psys::SubPlugin> result;

    for ( auto sub: _creators ) {

        if ( interface.compare( sub->subPluginInfo().interfaceId ) == 0 ) {

            result << sub;
        }
    }

    return result;
}

QMap<QString, QString> PFactoryPluginControllerPrivate::defaultInterfaces() const
{
    if ( _controller ) return _controller->defaultInterfaces ();

    return QMap<QString, QString>();
}

QList<psys::Plugin> PFactoryPluginControllerPrivate::plugins() const
{
    if ( _controller ) return _controller->plugins ();

    return _plugins;
}

void PFactoryPluginControllerPrivate::_loadPlugins()
{
    for ( auto p: _loader.allPluginsList () ) {

        auto plug = p.first;

        for ( const auto &subInfo: plug->subPluginInfoList () ) {

            if ( subInfo.interfaceId.compare ( subPluginInfo().interfaceId ) == 0 ) {

                if ( subInfo.id.compare( "Default plugin factory loader" ) == 0 ) {

                    _controller = std::dynamic_pointer_cast
                            <IPFactoryPluginController>( psys::SubPlugin( plug->create ( subInfo ) ) );

                    if ( _controller ) {

                        _plugins.clear ();
                        _creators.clear ();

                        _controller->setPluginsDirectory( _loader.pluginDirPath() );

                        return;
                    }
                }
            }

            _creators << psys::SubPlugin( plug->create ( subInfo ) );
        }

        _plugins << p.first;
    }

}
