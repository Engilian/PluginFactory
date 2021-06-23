#include "icreator_factory_plugin_loader.h"
using namespace pf;

ICreatorFactoryPluginLoader::ICreatorFactoryPluginLoader(const QString &id)
  : IObjectCreator<pf::IPluginLoader>( id )
{

}

ICreatorFactoryPluginLoader::~ICreatorFactoryPluginLoader()
{

}

pf::IPluginLoader *ICreatorFactoryPluginLoader::create() const
{
  throw( QString( "Not correct factory plugin loader creator " )
      .append ( typeid (this).name () )
      .append ( "::" )
      .append ( typeid ( pf::IPlugin ).name () )
      );
}
