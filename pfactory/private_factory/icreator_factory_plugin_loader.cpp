#include "icreator_factory_plugin_loader.h"
using namespace pf;

ICreatorFactoryPluginLoader::ICreatorFactoryPluginLoader(const QString &id)
  : IObjectCreator<psys::IPluginLoader>( id )
{

}

ICreatorFactoryPluginLoader::~ICreatorFactoryPluginLoader()
{

}

psys::IPluginLoader *ICreatorFactoryPluginLoader::create() const
{
  throw( QString( "Not correct factory plugin loader creator " )
      .append ( typeid (this).name () )
      .append ( "::" )
      .append ( typeid ( psys::IPlugin ).name () )
      );
}
