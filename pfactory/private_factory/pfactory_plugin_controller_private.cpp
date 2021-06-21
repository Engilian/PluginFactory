#include "pfactory_plugin_controller_private.h"
using namespace pf;

#include <QDir>
#include <QCoreApplication>

PFactoryPluginControllerPrivate::PFactoryPluginControllerPrivate()
  : IPFactoryPluginController( "PFactoryPluginControllerPrivate" )
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

    _creators.clear ();
    _loader.freeLoadedPlugins ();

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

  for ( auto sub: _creators.values () ) {

    if ( interface.compare( sub->subPluginInfo().interfaceId ) == 0 ) {

      result << sub;
    }
  }

  return result;
}

psys::PluginData PFactoryPluginControllerPrivate::plugin(psys::SubPlugin creator) const
{
  auto key = _creators.key( creator );
  for ( auto p: _loader.allPluginsList() )
    if ( p.uid() == key )
      return p;

  return psys::PluginData();
}

QList<psys::PluginData> PFactoryPluginControllerPrivate::plugins() const
{
  if ( _controller ) return _controller->plugins();

  return _loader.loadedPlugins ();
}

void PFactoryPluginControllerPrivate::_loadPlugins()
{
  _loader.loadAllPlugins ();

  for ( auto p: _loader.loadedPlugins() ) {
    for ( const auto &subInfo: p.plugin ()->subPluginInfoList () ) {

      if ( subInfo.interfaceId.compare ( subPluginInfo().interfaceId ) == 0 ) {

        if ( subInfo.id.compare( "Default plugin factory loader" ) == 0 ) {

          _controller = std::dynamic_pointer_cast
              <IPFactoryPluginController>( psys::SubPlugin( p.plugin ()->create ( subInfo ) ) );

          if ( _controller ) {

            _creators.clear ();
            _controller->setPluginsDirectory( _loader.pluginDirPath() );

            return;
          }
        }
      }

      if ( !_containsSubPlugin ( p.uid(), subInfo ) ) {

        auto subPlugin = psys::SubPlugin( p.plugin ()->create ( subInfo ) );

        if ( subPlugin ) {
          _creators.insertMulti ( p.uid() , subPlugin );
        }
        else {

          fprintf ( stderr, "error load sub plugin: %s -> %s",
                    QString( p.fileName () + "(" + p.uid () + ")" ).toStdString ().c_str (),
                    subInfo.id.toStdString ().c_str () );
        }
      }
    }
  }

}

bool PFactoryPluginControllerPrivate::_containsSubPlugin(const QString &pluginId, const psys::SubPluginInfo &info) const
{
  for ( auto &i: _creators.values ( pluginId ) ) {

    if ( i->subPluginInfo ().id == info.id )
      return true;
  }

  return  false;
}
