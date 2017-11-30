#ifndef FACTORY_PLUGIN_LOADER_PRIVATE_H
#define FACTORY_PLUGIN_LOADER_PRIVATE_H

#include <QHash>

#include "pfactory/plugin/loader/ifactory_plugin_loader.h"

namespace pfactory {

class FactoryPluginLoaderPrivate : public IFactoryPluginLoader
{
public:
    FactoryPluginLoaderPrivate();
    ~FactoryPluginLoaderPrivate();
public:
    QString pluginDirPath() const;
    void setPluginDirPath( const QString &path );
public:
    bool isRecursiveLoad() const;
    void setRecursiveLoad( bool enable );
public:
    QList<std::pair<FactoryPlugin, QString>> allPluginsList() const;
public:
    bool loadPlugin( const QString &pluginPath );
    QList<std::pair<QString, bool>> loadPluginList(
            QList<QString> pathes
            );
    QList<FactoryPlugin> loadedPlugins() const;
    FactoryPlugin loadedPlugin( const QString &id ) const;
    bool isLoadedPlugin( const QString &id ) const;
public:
    void freeLoadedPlugins();
    void freePlugin( const QString &pluginId );
private:
    ///
    /// \brief Get a list of plugin files in the directory
    /// \param dirPath directory path
    /// \param recursive on/off recursive load
    /// \return plugins path
    ///
    QStringList _findPluginFiles( const QString &dirPath, bool recursive ) const;

    ///
    /// \brief Load plugin
    /// \param path plugin path
    /// \return if the pointer to the plug-in is successful, otherwise empty
    ///
    FactoryPlugin _loadPlugin( const QString &path ) const;
private:
    ///
    /// \brief Path for plugin directory
    ///
    QString         _pluginDirectoryPath;

    ///
    /// \brief Recursive loading of a package with plugins
    ///
    bool            _isRecursiveLoad;
private:
    ///
    /// \brief Loaded plugins
    /// \details std::pair<Plugin, plugin path>
    ///
    QHash<QString, FactoryPlugin>   _plugins;
};

}



#endif // FACTORY_PLUGIN_LOADER_PRIVATE_H
