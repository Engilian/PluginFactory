#pragma once
#include "iplugin.h"

namespace pf
{
  class PluginData
  {
  public:
    using PluginP = std::shared_ptr<IPlugin>;
  private:
    QString m_uid;
    QString m_path;
    PluginP m_plugin;
  public:
    PluginData();
    PluginData(std::shared_ptr<IPlugin> plugin, const QString &path);
    PluginData(const PluginData &info);
    ~PluginData();
  public:
    QString uid() const;
    QString fileName() const;
    QString absoluteFilePath() const;
    std::shared_ptr<IPlugin> plugin() const;
  };

  ///
  /// \brief The PFactoryPluginControllerPrivate class
  ///
  class PluginController final
  {
    class Loader;
    using LoaderP = std::shared_ptr<Loader>;
    LoaderP   _loader;
  public:
    PluginController();
    ~PluginController();

  public:
    QList<pf::PluginData> plugins() const;
    QList<pf::Creator> creators(const QString &interface) const;
  };
}
