#pragma once
#include <QMap>

#include "psys/iplugin.h"
#include "psys/plugin_data.h"
#include "psys/isub_plugin.h"
#include "object_creator.h"

namespace pf {

  class IPFactoryPluginController;
  using PFactoryPluginController = std::shared_ptr<IPFactoryPluginController>;

  ///
  /// \brief Plug-in Load Controller Interface
  ///
  class IPFactoryPluginController
      : public psys::ISubPlugin
  {
  protected:
    ///
    /// \brief Constructor
    /// \param id plugin id
    /// \param desc plugin description
    ///
    IPFactoryPluginController(const QString &id);
  public:
    virtual ~IPFactoryPluginController();
  public:
    ///
    /// \brief Set the path to the folder with plugins
    /// \param path
    ///
    virtual void setPluginsDirectory( const QString &path ) = 0;

    ///
    /// \brief path to the folder with plugins
    /// \return path new path to the folder
    ///
    virtual QString pluginsDirectory() const = 0;
  public:
    ///
    /// \brief Get information about the parent plugin
    /// \param creator sub plugin
    /// \return parent plugin info
    ///
    virtual psys::PluginData plugin(psys::SubPlugin creator) const = 0;

    ///
    /// \brief Get list creators sub pl
    /// \param interface string interface
    /// \return list creator subPlugin
    ///
    virtual QList<psys::SubPlugin> creators(const QString &interface) const = 0;
  public:
    ///
    /// \brief List of loaded plugins
    ///
    virtual QList<psys::PluginData> plugins() const = 0;
  };

}
