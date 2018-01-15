#include "plugin_loader.h"
using namespace psys;

#include "private/plugin_loader_private.h"

PluginLoader::PluginLoader(psys::IPluginLoader *loader):
    IPluginLoader(),
    _d( loader )
{
    if ( !_d ) loadDefaultLoader();
}

PluginLoader::~PluginLoader()
{

}

void PluginLoader::loadDefaultLoader()
{
    _d = _FPluginLoader( new PluginLoaderPrivate() );
}

void PluginLoader::setLoader(IPluginLoader *loader)
{
    _d.reset();
    _d = _FPluginLoader( loader );
}

QString PluginLoader::pluginDirPath() const
{
    return _d->pluginDirPath();
}

void PluginLoader::setPluginDirPath(const QString &path)
{
    _d->setPluginDirPath( path );
}

bool PluginLoader::isRecursiveLoad() const
{
    return _d->isRecursiveLoad();
}

void PluginLoader::setRecursiveLoad(bool enable)
{
    _d->setRecursiveLoad( enable );
}

QList<std::pair<Plugin, QString> > PluginLoader::allPluginsList() const
{
    return _d->allPluginsList();
}

bool PluginLoader::loadPlugin(const QString &pluginPath)
{
    return _d->loadPlugin( pluginPath );
}

QList<std::pair<QString, bool> > PluginLoader::loadPluginList(
        QList<QString> pathes )
{
    return _d->loadPluginList( pathes );
}

QList<Plugin> PluginLoader::loadedPlugins() const
{
    return _d->loadedPlugins();
}

Plugin PluginLoader::loadedPlugin(const QString &id) const
{
    return _d->loadedPlugin( id );
}

bool PluginLoader::isLoadedPlugin(const QString &id) const
{
    return _d->isLoadedPlugin( id );
}

void PluginLoader::freeLoadedPlugins()
{
    _d->freeLoadedPlugins();
}

void PluginLoader::freePlugin(const QString &pluginId)
{
    _d->freePlugin( pluginId );
}