#include "factory_plugin_loader_private.h"
using namespace pfactory;

#include <QDir>
#include <QDebug>
#include <QPluginLoader>
#include <QCoreApplication>

FactoryPluginLoaderPrivate::FactoryPluginLoaderPrivate():
    IFactoryPluginLoader(),
    _pluginDirectoryPath(
        QDir::fromNativeSeparators( QCoreApplication::applicationDirPath() +
                                    "/plug" )
        ),
    _isRecursiveLoad( true )

{

}

FactoryPluginLoaderPrivate::~FactoryPluginLoaderPrivate()
{

}

QString FactoryPluginLoaderPrivate::pluginDirPath() const
{
    return  _pluginDirectoryPath;
}

void FactoryPluginLoaderPrivate::setPluginDirPath(const QString &path)
{
    _pluginDirectoryPath = path;
}

bool FactoryPluginLoaderPrivate::isRecursiveLoad() const
{
    return _isRecursiveLoad;
}

void FactoryPluginLoaderPrivate::setRecursiveLoad(bool enable)
{
    _isRecursiveLoad = enable;
}

QList<std::pair<FactoryPlugin, QString> > FactoryPluginLoaderPrivate::allPluginsList() const
{
    QList<std::pair<FactoryPlugin, QString> > plugins;

    QStringList pathes = _findPluginFiles( _pluginDirectoryPath, _isRecursiveLoad );

    for ( const QString &path: pathes ) {

        auto p  = _loadPlugin( path );

        if ( p ) {

            plugins << std::pair<FactoryPlugin, QString>( p, path );
        }
    }

    return plugins;
}

bool FactoryPluginLoaderPrivate::loadPlugin(const QString &pluginPath)
{
    auto p = _loadPlugin( pluginPath );

    if ( p ) {

        if ( _plugins.contains( p->name() ) ) {

            return false;
        }
        else {

            _plugins[ p->name() ] = p;
            return true;
        }
    }

    return false;
}

QList<std::pair<QString, bool> > FactoryPluginLoaderPrivate::loadPluginList(QList<QString> pathes)
{
    QList<std::pair<QString, bool> > result;

    for ( const QString &path: pathes ) {

        result << std::pair<QString, bool>( path, loadPlugin( path ) );
    }

    return result;
}

QList<FactoryPlugin> FactoryPluginLoaderPrivate::loadedPlugins() const
{
    return _plugins.values();
}

FactoryPlugin FactoryPluginLoaderPrivate::loadedPlugin(const QString &id) const
{
    return _plugins[ id ];
}

bool FactoryPluginLoaderPrivate::isLoadedPlugin(const QString &id) const
{
    return _plugins.contains( id );
}

void FactoryPluginLoaderPrivate::freeLoadedPlugins()
{
    _plugins.clear();
}

void FactoryPluginLoaderPrivate::freePlugin(const QString &pluginId)
{
    if ( _plugins.contains( pluginId ) ) {

        _plugins.remove( pluginId );
    }
}

QStringList FactoryPluginLoaderPrivate::_findPluginFiles(const QString &dirPath,
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

            if ( !dirName.isEmpty() && directory.exists( dirName ) ) {

                result << directory.absolutePath() + "/" + dirName;
            }
        }

    }

    return result;
}

FactoryPlugin FactoryPluginLoaderPrivate::_loadPlugin(const QString &path) const
{
    QPluginLoader loader( path );

    if ( loader.load() ) {

        auto *p = qobject_cast<IFactoryPlugin *>( loader.instance() );

        if ( p ) {

            return FactoryPlugin( p );
        }
    }

    return FactoryPlugin();
}
