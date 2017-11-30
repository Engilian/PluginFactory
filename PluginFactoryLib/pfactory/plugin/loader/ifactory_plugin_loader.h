#ifndef IFACTORY_PLUGIN_LOADER_H
#define IFACTORY_PLUGIN_LOADER_H

#include "pfactory/plugin/ifactory_plugin.h"

namespace pfactory {

///
/// \brief Plugin load interface
///
class IFactoryPluginLoader
{
protected:
    IFactoryPluginLoader();
public:
    virtual ~IFactoryPluginLoader();
public:
    ///
    /// \brief Path to the folder with plugins
    /// \return string path
    ///
    virtual QString pluginDirPath() const = 0;

    ///
    /// \brief Set the path to the folder with plugins
    /// \param path path to the folder with plugins
    ///
    virtual void setPluginDirPath( const QString &path ) = 0;
public:
    ///
    /// \brief Recursive loading of a package with plugins
    /// \return If recursive loading is true, otherwise false
    ///
    virtual bool isRecursiveLoad() const = 0;

    ///
    /// \brief Set recursive loading of a package with
    ///  pluginssetRecursiveLoad
    /// \param enable on/off recursive load
    ///
    virtual void setRecursiveLoad( bool enable ) = 0;
public:

    ///
    /// \brief Get all plugins in plugin directory path
    /// \return list pair<Plugin, Plugin file path>
    ///
    virtual QList<std::pair<FactoryPlugin, QString>> allPluginsList() const = 0;
public:

    ////
    /// \brief Load plugin
    /// \param pluginPath plagin file path
    /// \return If the plugin is loaded true, the truth is false
    ///
    virtual bool loadPlugin( const QString &pluginPath ) = 0;

    ///
    /// \brief Load plugin list
    /// \param pathes List of pathways to plugins
    /// \return Load results list
    ///
    virtual QList<std::pair<QString, bool>> loadPluginList(
            QList<QString> pathes
            ) = 0;

    ///
    /// \brief All loaded plugin
    /// \return plugin list
    ///
    virtual QList<FactoryPlugin> loadedPlugins() const = 0;

    ///
    /// \brief Get loaded plugin
    /// \param id loaded plugin id
    /// \return if the pointer to the plug-in is successful, otherwise empty
    ///
    virtual FactoryPlugin loadedPlugin( const QString &id ) const = 0;

    ///
    /// \brief isLoadedPlugin
    /// \param id loaded plugin id
    /// \return if loaded true, otherwise false
    ///
    virtual bool isLoadedPlugin( const QString &id ) const = 0;

    ///
    /// \brief Unload all loaded plugins
    ///
    virtual void freeLoadedPlugins() = 0;

    ///
    /// \brief Unload loaded plugin
    /// \param pluginId id loaded plugin
    ///
    virtual void freePlugin( const QString &pluginId ) = 0;
};

}

#endif // IFACTORY_PLUGIN_LOADER_H
