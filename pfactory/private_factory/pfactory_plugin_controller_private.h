#pragma once
#include <QMap>
#include <QMultiMap>

#include "pfactory/plugin_interfaces/ipfactory_plugin_controller.h"
#include <pfactory/plugin/psys/loader/plugin_loader.h>

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
    psys::PluginData plugin(psys::SubPlugin creator) const;
    QList<psys::SubPlugin> creators(const QString &interface) const;

  public:
    QList<psys::PluginData> plugins() const;

  protected:
    void _loadPlugins();
    bool _containsSubPlugin(const QString &pluginId, const psys::SubPluginInfo &info ) const;
  private:
    psys::PluginLoader                  _loader;
    PFactoryPluginController            _controller;
    QMultiMap<QString, psys::SubPlugin> _creators;
  };

}
