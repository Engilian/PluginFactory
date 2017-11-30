#include "factory_plugin_loader.h"
using namespace pfactory;

#include "private/factory_plugin_loader_private.h"

FactoryPluginLoader::FactoryPluginLoader(pfactory::IFactoryPluginLoader *loader):
    IFactoryPluginLoader(),
    _d( loader )
{

    if ( !_d ) {

        loadDefaultLoader();
    }
}

FactoryPluginLoader::~FactoryPluginLoader()
{

}

void FactoryPluginLoader::loadDefaultLoader()
{
    _d = _FPluginLoader( new FactoryPluginLoaderPrivate() );
}

void FactoryPluginLoader::setLoader(IFactoryPluginLoader *loader)
{
    _d.reset();
    _d = _FPluginLoader( loader );
}

QString FactoryPluginLoader::pluginDirPath() const
{
    return _d->pluginDirPath();
}

void FactoryPluginLoader::setPluginDirPath(const QString &path)
{
    _d->setPluginDirPath( path );
}

bool FactoryPluginLoader::isRecursiveLoad() const
{
    return _d->isRecursiveLoad();
}

void FactoryPluginLoader::setRecursiveLoad(bool enable)
{
    _d->setRecursiveLoad( enable );
}

QList<std::pair<FactoryPlugin, QString> > FactoryPluginLoader::allPluginsList() const
{
    return _d->allPluginsList();
}

bool FactoryPluginLoader::loadPlugin(const QString &pluginPath)
{
    return _d->loadPlugin( pluginPath );
}

QList<std::pair<QString, bool> > FactoryPluginLoader::loadPluginList(
        QList<QString> pathes )
{
    return _d->loadPluginList( pathes );
}

QList<FactoryPlugin> FactoryPluginLoader::loadedPlugins() const
{
    return _d->loadedPlugins();
}

FactoryPlugin FactoryPluginLoader::loadedPlugin(const QString &id) const
{
    return _d->loadedPlugin( id );
}

bool FactoryPluginLoader::isLoadedPlugin(const QString &id) const
{
    return _d->isLoadedPlugin( id );
}

void FactoryPluginLoader::freeLoadedPlugins()
{
    _d->freeLoadedPlugins();
}

void FactoryPluginLoader::freePlugin(const QString &pluginId)
{
    _d->freePlugin( pluginId );
}
