#include "plugin_loader_private.h"
using namespace psys;

#include <QDir>
#include <QDebug>
#include <QPluginLoader>
#include <QCoreApplication>

PluginLoaderPrivate::PluginLoaderPrivate():
    IPluginLoader(),
    _pluginDirectoryPath(
        QDir::fromNativeSeparators( QCoreApplication::applicationDirPath() +
                                    "/plug" )
        ),
    _isRecursiveLoad( true )

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

QList<std::pair<Plugin, QString> > PluginLoaderPrivate::allPluginsList() const
{
    QList<std::pair<Plugin, QString> > plugins;

    QStringList pathes = _findPluginFiles( _pluginDirectoryPath, _isRecursiveLoad );

    for ( const QString &path: pathes ) {

        auto p  = _loadPlugin( path );

        if ( p ) {

            plugins << std::pair<Plugin, QString>( p, path );
        }
    }

    return plugins;
}

void PluginLoaderPrivate::loadAllPlugins()
{
    loadPluginList ( _findPluginFiles( _pluginDirectoryPath, _isRecursiveLoad ) );
}


bool PluginLoaderPrivate::loadPlugin(const QString &pluginPath)
{
    auto p = _loadPlugin( pluginPath );

    if ( p ) {

        if ( _plugins.contains( p->id () ) ) {

            return false;
        }
        else {
            auto pinfo = PluginInfo( p, pluginPath );
            _plugins[ p->id() ] = pinfo;
            return true;
        }
    }

    return false;
}

QList<std::pair<QString, bool> > PluginLoaderPrivate::loadPluginList(QList<QString> pathes)
{
    QList<std::pair<QString, bool> > result;

    for ( const QString &path: pathes ) {

        result << std::pair<QString, bool>( path, loadPlugin( path ) );
    }

    return result;
}

QList<Plugin> PluginLoaderPrivate::loadedPlugins() const
{
    QList<Plugin> result;
    for ( auto &info: _plugins.values () ) result << info.plugin ();
    return result;
}

Plugin PluginLoaderPrivate::loadedPlugin(const QString &id) const
{
    return _plugins[ id ].plugin ();
}

QList<PluginInfo> PluginLoaderPrivate::loadedPluginsInfo() const
{
    return _plugins.values ();
}

PluginInfo PluginLoaderPrivate::loadedPluginInfo(const QString &id) const
{
    return _plugins[ id ];
}

bool PluginLoaderPrivate::isLoadedPlugin(const QString &id) const
{
    return _plugins.contains( id );
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
    QStringList filter{ "*.so","*,SO","*.So","*.dll", "*.DLL", "*.Dll" };
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

Plugin PluginLoaderPrivate::_loadPlugin(const QString &path) const
{
    QPluginLoader loader( path );

    if ( loader.load() ) {

        auto *p = qobject_cast<IPlugin *>( loader.instance() );

        if ( p ) {

            return Plugin( p );
        }
    }
    else {
        qDebug() << "error load plugin: " << QFileInfo( path ).fileName () << ":"
                 << loader.errorString ();
    }

    return Plugin();
}
