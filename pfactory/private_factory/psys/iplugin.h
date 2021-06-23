#pragma once
#include <QString>
#include <QObject>
#include <memory>

#include "isub_plugin.h"

#ifndef FACTORY_PLUGIN_VALID_STRING
#define FACTORY_PLUGIN_VALID_STRING \
  "ru.engilian@gmail.com.Factorypfactory/plugin/1.1"
#endif


namespace pf
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

Q_DECLARE_INTERFACE(pf::IPlugin, FACTORY_PLUGIN_VALID_STRING);
