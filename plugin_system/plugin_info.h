#pragma once
#include <memory>
#include <QString>

namespace psys {

class IPlugin;

class PluginInfo
{
    QString _uid;
    QString _path;

    std::shared_ptr<IPlugin> _plugin;
public:
    PluginInfo();
    PluginInfo( std::shared_ptr<IPlugin> plugin, const QString &path );
    PluginInfo( const PluginInfo &info );
    ~PluginInfo();
public:
    QString uid() const;

    QString fileName() const;
    QString absoluteFilePath() const;

    std::shared_ptr<IPlugin> plugin() const;
};

}