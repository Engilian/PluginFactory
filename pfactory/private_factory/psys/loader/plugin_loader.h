#pragma once
#include "iplugin_loader.h"

namespace psys {

  ///
  /// \brief Plugin download interface
  ///
  class PluginLoader
      : public IPluginLoader
  {
    // Shared pointer for instance plugin loader
    using _FPluginLoader = std::shared_ptr<IPluginLoader>;
    _FPluginLoader  _d;
  public:
    ///
    /// \brief Constructor
    /// \param Implementation of the interface for loading plug-ins.
    ///
    PluginLoader(IPluginLoader *loader = nullptr);
    virtual ~PluginLoader();
  public:
    ///
    /// \brief Load default plugin loader class
    ///
    void loadDefaultLoader();

    ////
    /// \brief Set plugin loader class
    /// \param loader plugin loader
    ///
    void setLoader(IPluginLoader *loader);
  public:
    QString pluginDirPath() const override;
    void setPluginDirPath(const QString &path) override;
  public:
    bool isRecursiveLoad() const override;
    void setRecursiveLoad(bool enable) override;
  public:
    QList<PluginData> allPluginsList() const override;
  public:
    void loadAllPlugins() override;
    LoadResult loadPlugin(const QString &pluginPath) override;
    QList<LoadResult> loadPluginList(const QStringList &pathes) override;
    QList<PluginData> loadedPlugins() const override;
  public:
    void freeLoadedPlugins() override;
    void freePlugin(const QString &pluginId) override;
  };
}
