#include "plugin_loader.h"
using namespace psys;

#include "plugin_loader_private.h"

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

QList<PluginData> PluginLoader::allPluginsList() const
{
  return _d->allPluginsList();
}

void PluginLoader::loadAllPlugins()
{
  return _d->loadAllPlugins ();
}

IPluginLoader::LoadResult PluginLoader::loadPlugin(const QString &pluginPath)
{
  return _d->loadPlugin( pluginPath );
}

QList<IPluginLoader::LoadResult> PluginLoader::loadPluginList(const QStringList &pathes )
{
  return _d->loadPluginList( pathes );
}

QList<PluginData> PluginLoader::loadedPlugins() const
{
  return _d->loadedPlugins();
}

void PluginLoader::freeLoadedPlugins()
{
  _d->freeLoadedPlugins();
}

void PluginLoader::freePlugin(const QString &pluginId)
{
  _d->freePlugin( pluginId );
}
