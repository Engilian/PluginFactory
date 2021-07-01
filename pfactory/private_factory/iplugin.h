#pragma once
#include <QString>
#include <QObject>
#include <memory>

#include "object_creator.h"

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
    virtual QList<Creator> creators() const = 0;
  };
}

Q_DECLARE_INTERFACE(pf::IPlugin, FACTORY_PLUGIN_VALID_STRING);
