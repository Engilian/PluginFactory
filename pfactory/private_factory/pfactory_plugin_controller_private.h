#pragma once
#include <QMap>
#include <QMultiMap>

#include "psys/loader/plugin_loader.h"
#include "ipfactory_plugin_controller.h"

namespace pf
{
  ///
  /// \brief The PFactoryPluginControllerPrivate class
  ///
  class PFactoryPluginControllerPrivate
      : public IPFactoryPluginController
  {
  public:
    PFactoryPluginControllerPrivate();
    ~PFactoryPluginControllerPrivate();
  public:
    void setPluginsDirectory(const QString &path);
    QString pluginsDirectory() const;

  public:
    pf::PluginData plugin(pf::SubPlugin creator) const;
    QList<pf::SubPlugin> creators(const QString &interface) const;

  public:
    QList<pf::PluginData> plugins() const;

  protected:
    void _loadPlugins();
    bool _containsSubPlugin(const QString &pluginId, const pf::SubPluginInfo &info ) const;
  private:
    pf::PluginLoader                  _loader;
    PFactoryPluginController            _controller;
    QMultiMap<QString, pf::SubPlugin> _creators;
  };

}
