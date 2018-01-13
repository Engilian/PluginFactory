#ifndef FACTORY_PLUGIN_LOADER_H
#define FACTORY_PLUGIN_LOADER_H

#include "iplugin_loader.h"

namespace psys {

///
/// \brief Plugin download interface
///
class PluginLoader: public IPluginLoader
{
    // Shared pointer for instance plugin loader
    using _FPluginLoader = std::shared_ptr<IPluginLoader>;
    _FPluginLoader  _d;
public:
    ///
    /// \brief Constructor
    /// \param Implementation of the interface for loading plug-ins.
    ///
    PluginLoader( IPluginLoader *loader = nullptr );
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
    void setLoader( IPluginLoader *loader );
public:
    QString pluginDirPath() const;
    void setPluginDirPath( const QString &path );
public:
    bool isRecursiveLoad() const;
    void setRecursiveLoad( bool enable );
public:
    QList<std::pair<Plugin, QString>> allPluginsList() const;
public:
    bool loadPlugin( const QString &pluginPath );
    QList<std::pair<QString, bool>> loadPluginList(
            QList<QString> pathes
            );
    QList<Plugin> loadedPlugins() const;
    Plugin loadedPlugin( const QString &id ) const;
    bool isLoadedPlugin( const QString &id ) const;
public:
    void freeLoadedPlugins();
    void freePlugin( const QString &pluginId );

};

}



#endif // FACTORY_PLUGIN_LOADER_H
