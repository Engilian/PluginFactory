#ifndef FACTORY_PLUGIN_LOADER_H
#define FACTORY_PLUGIN_LOADER_H

#include "ifactory_plugin_loader.h"

namespace pfactory {

///
/// \brief Plugin download interface
///
class FactoryPluginLoader: public IFactoryPluginLoader
{
public:
    ///
    /// \brief Constructor
    /// \param Implementation of the interface for loading plug-ins.
    ///
    FactoryPluginLoader( IFactoryPluginLoader *loader = nullptr );
    virtual ~FactoryPluginLoader();
public:
    ///
    /// \brief Load default plugin loader class
    ///
    void loadDefaultLoader();

    ////
    /// \brief Set plugin loader class
    /// \param loader plugin loader
    ///
    void setLoader( IFactoryPluginLoader *loader );
public:
    QString pluginDirPath() const;
    void setPluginDirPath( const QString &path );
public:
    bool isRecursiveLoad() const;
    void setRecursiveLoad( bool enable );
public:
    QList<std::pair<FactoryPlugin, QString>> allPluginsList() const;
public:
    bool loadPlugin( const QString &pluginPath );
    QList<std::pair<QString, bool>> loadPluginList(
            QList<QString> pathes
            );
    QList<FactoryPlugin> loadedPlugins() const;
    FactoryPlugin loadedPlugin( const QString &id ) const;
    bool isLoadedPlugin( const QString &id ) const;
public:
    void freeLoadedPlugins();
    void freePlugin( const QString &pluginId );
private:
    // Shared pointer for instance plugin loader
    using _FPluginLoader = std::shared_ptr<IFactoryPluginLoader>;

    ///
    /// \brief Factical loader
    ///
    _FPluginLoader  _d;

};

}



#endif // FACTORY_PLUGIN_LOADER_H
