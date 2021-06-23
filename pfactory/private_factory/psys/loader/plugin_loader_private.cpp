#include "plugin_loader_private.h"
using namespace pf;

#include <QDir>
#include <QDebug>
#include <QPluginLoader>
#include <QCoreApplication>

PluginLoaderPrivate::PluginLoaderPrivate()
  : IPluginLoader()
  , _pluginDirectoryPath(
      QDir::fromNativeSeparators( QCoreApplication::applicationDirPath() + "/plug" ) )
  , _isRecursiveLoad( true )

{
  setPluginDirPath ( _pluginDirectoryPath );
}

PluginLoaderPrivate::~PluginLoaderPrivate()
{

}

QString PluginLoaderPrivate::pluginDirPath() const
{
  return  _pluginDirectoryPath;
}

void PluginLoaderPrivate::setPluginDirPath(const QString &path)
{
  _pluginDirectoryPath = path;

  QDir d( _pluginDirectoryPath );

  if ( !d.exists () ) {

    d.mkpath ( "." );
  }
}

bool PluginLoaderPrivate::isRecursiveLoad() const
{
  return _isRecursiveLoad;
}

void PluginLoaderPrivate::setRecursiveLoad(bool enable)
{
  _isRecursiveLoad = enable;
}

QList<PluginData> PluginLoaderPrivate::allPluginsList() const
{
  QList<PluginData> plugins;

  QStringList pathes = _findPluginFiles( _pluginDirectoryPath, _isRecursiveLoad );

  for ( const QString &path: pathes ) {
    auto p  = _loadPlugin( path );

    if ( p.ok ) {
      plugins << p.data;
    }
  }

  return plugins;
}

void PluginLoaderPrivate::loadAllPlugins()
{
  loadPluginList ( _findPluginFiles( _pluginDirectoryPath, _isRecursiveLoad ) );
}


IPluginLoader::LoadResult PluginLoaderPrivate::loadPlugin(const QString &pluginPath)
{
  auto result = _loadPlugin( pluginPath );

  if ( result.ok ) {

    // Check is loaded plugin
    if ( _plugins.contains( result.data.uid() ) ) {
      result.ok = false;
      result.errorString = "Plugin is already loaded";
    }

    // Add plugin to data
    else {
      _plugins[ result.data.uid() ] = result.data;
    }
  }

  return result;
}

QList<IPluginLoader::LoadResult> PluginLoaderPrivate::loadPluginList(const QStringList &pathes)
{
  QList<LoadResult> result;
  for ( const QString &path: pathes )
    result << loadPlugin( path );
  return result;
}

QList<PluginData> PluginLoaderPrivate::loadedPlugins() const
{
  return _plugins.values();
}

void PluginLoaderPrivate::freeLoadedPlugins()
{
  _plugins.clear();
}

void PluginLoaderPrivate::freePlugin(const QString &pluginId)
{
  if ( _plugins.contains( pluginId ) ) {

    _plugins.remove( pluginId );
  }
}

QStringList PluginLoaderPrivate::_findPluginFiles(const QString &dirPath,
                                                  bool recursive) const
{
#ifdef __unix__
  QStringList filter{ "*.so","*,SO","*.So" };
#else
  QStringList filter{ "*.dll", "*.DLL", "*.Dll" };
#endif
  QDir directory = QDir::fromNativeSeparators( dirPath );

  QStringList result;
  if ( !directory.exists() ) {

    qDebug() << "Directory " + directory.absolutePath() + " not exists";
    return result;
  }

  for ( const QString &name: directory.entryList ( filter, QDir::Files ) ) {

    result << directory.absoluteFilePath( name );
  }

  if ( recursive ) {

    for ( const QString &name: directory.entryList( QDir::Dirs ) ) {

      QString dirName = QDir::cleanPath( name );

      if ( dirName.length () >= 3 ) {

        if ( !dirName.isEmpty() && directory.exists( dirName ) ) {

          result << directory.absolutePath() + "/" + dirName;
        }

      }
    }

  }

  return result;
}

IPluginLoader::LoadResult PluginLoaderPrivate::_loadPlugin(const QString &path) const
{
  QPluginLoader loader( path );

  LoadResult result;
  result.ok   = false;
  result.data = PluginData( Plugin(), path );

  if ( loader.load() ) {
    auto *p = qobject_cast<IPlugin *>( loader.instance() );

    if ( !!p ) {
      result.ok   = true;
      result.data = PluginData( Plugin( p ), path );
      return result;
    } else {
      result.errorString = "Error create plugin instance";
    }
  }
  else {
    result.errorString = loader.errorString();
    qDebug() << "error load plugin: " << QFileInfo( path ).fileName () << ":"
                 << loader.errorString ();
  }

  return result;
}
