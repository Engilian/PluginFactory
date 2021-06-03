#pragma once
#include <QHash>
#include <plugin_system/loader/iplugin_loader.h>

namespace psys {

class PluginLoaderPrivate : public IPluginLoader
{
public:
    PluginLoaderPrivate();
    ~PluginLoaderPrivate();
public:
    QString pluginDirPath() const override;
    void setPluginDirPath( const QString &path ) override;
public:
    bool isRecursiveLoad() const override;
    void setRecursiveLoad( bool enable ) override;
public:
    QList<std::pair<Plugin, QString>> allPluginsList() const override;
public:
    void loadAllPlugins() override;
    bool loadPlugin( const QString &pluginPath ) override;
    QList<std::pair<QString, bool>> loadPluginList( QList<QString> pathes ) override;
    QList<Plugin> loadedPlugins() const override;
    Plugin loadedPlugin( const QString &id ) const override;
    QList<PluginInfo> loadedPluginsInfo() const override;
    PluginInfo loadedPluginInfo( const QString &id ) const override;

    bool isLoadedPlugin( const QString &id ) const override;
public:
    void freeLoadedPlugins() override;
    void freePlugin( const QString &pluginId ) override;
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
    Plugin _loadPlugin( const QString &path ) const;
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
    QHash<QString, PluginInfo>   _plugins;
};

}
