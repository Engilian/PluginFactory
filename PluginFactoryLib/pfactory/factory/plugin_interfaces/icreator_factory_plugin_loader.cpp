#include "icreator_factory_plugin_loader.h"
using namespace pfactory;

ICreatorFactoryPluginLoader::ICreatorFactoryPluginLoader(const QString &id):
    IObjectCreator<IFactoryPluginLoader>( id )
{

}

ICreatorFactoryPluginLoader::~ICreatorFactoryPluginLoader()
{

}

IFactoryPluginLoader *ICreatorFactoryPluginLoader::create() const
{
    throw( QString( "Not correct factory plugin loader creator " )
            .append ( typeid (this).name () )
            .append ( "::" )
            .append ( typeid ( IFactoryPlugin ).name () )
            );
}
