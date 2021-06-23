#pragma once
#include <QHash>
#include "iplugin_loader.h"

namespace pf
{

  class PluginLoaderPrivate final
      : public IPluginLoader
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
    QList<PluginData> allPluginsList() const override;

  public:
    void loadAllPlugins() override;
    LoadResult loadPlugin(const QString &pluginPath) override;
    QList<LoadResult> loadPluginList(const QStringList &pathes ) override;
    QList<PluginData> loadedPlugins() const override;

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
    QStringList _findPluginFiles(const QString &dirPath, bool recursive) const;

    ///
    /// \brief Load plugin
    /// \param path plugin path
    /// \return if the pointer to the plug-in is successful, otherwise empty
    ///
    LoadResult _loadPlugin(const QString &path) const;
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
    QHash<QString, PluginData>   _plugins;
  };

}
