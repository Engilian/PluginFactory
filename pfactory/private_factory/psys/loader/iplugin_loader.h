#pragma once
#include "../iplugin.h"
#include "../plugin_data.h"

namespace psys
{

  ///
  /// \brief Plugin load interface
  ///
  class IPluginLoader
  {
  public:
    struct LoadResult
    {
      bool        ok = false;
      PluginData  data;
      QString     errorString;
    };
  protected:
    IPluginLoader();
  public:
    virtual ~IPluginLoader();
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
    virtual void setPluginDirPath(const QString &path) = 0;
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
    virtual void setRecursiveLoad(bool enable) = 0;
  public:

    ///
    /// \brief Get all plugins in plugin directory path
    /// \return list pair<Plugin, Plugin file path>
    ///
    virtual QList<PluginData> allPluginsList() const = 0;
  public:

    virtual void loadAllPlugins() = 0;

    ////
    /// \brief Load plugin
    /// \param pluginPath plagin file path
    /// \return If the plugin is loaded true, the truth is false
    ///
    virtual LoadResult loadPlugin(const QString &pluginPath) = 0;

    ///
    /// \brief Load plugin list
    /// \param pathes List of pathways to plugins
    /// \return Load results list
    ///
    virtual QList<LoadResult> loadPluginList(const QStringList &pathes) = 0;

    ///
    /// \brief All loaded plugin
    /// \return plugin list
    ///
    virtual QList<PluginData> loadedPlugins() const = 0;

    ///
    /// \brief Unload all loaded plugins
    ///
    virtual void freeLoadedPlugins() = 0;

    ///
    /// \brief Unload loaded plugin
    /// \param pluginId id loaded plugin
    ///
    virtual void freePlugin(const QString &pluginId) = 0;
  };

}
