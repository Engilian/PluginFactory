#pragma once
#include <memory>
#include <QString>

namespace pf
{
  class IPlugin;
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
}
