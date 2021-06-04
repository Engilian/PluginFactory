#pragma once
#include <QString>
#include <QObject>
#include <memory>

#include "isub_plugin.h"

#define FACTORY_PLUGIN_VALID_STRING \
  "ru.engilian@gmail.com.Factorypfactory/plugin/1.1"

namespace psys
{
  class IPlugin;
  using Plugin = std::shared_ptr<IPlugin>;

  ///
  /// \brief Interface Plagin for Factory
  ///
  class IPlugin
  {
  protected:
    IPlugin();
  public:
    virtual ~IPlugin();

  public:
    ///
    /// \brief Compare versions
    /// \param v versionPlugin
    /// \return if the version of the plugin is greater than the current true,
    ///  otherwise it is false
    ///
    virtual bool versionComparer( const QString &v ) const;
  public:
    ///
    /// \brief List of information implemented plugins
    /// \return list information
    ///
    virtual QList<SubPluginInfo> subPluginInfoList() const = 0;

    ///
    /// \brief Create a sub plugin
    /// \param id sub plugin id
    /// \warning If there is no sub plug-in, it returns nullptr
    /// \return sub plugin
    ///
    virtual ISubPlugin *create(const QString &id) const = 0;

    ///
    /// \brief Create a sub plugin
    /// \param info information implemented plugin
    /// \warning If there is no sub plug-in, it returns nullptr
    /// \return sub plugin
    ///
    virtual ISubPlugin *create(const SubPluginInfo &info) const;
  };

}

Q_DECLARE_INTERFACE( psys::IPlugin, FACTORY_PLUGIN_VALID_STRING );
