#ifndef ICREATOR_FACTORY_PLUGIN_LOADER_H
#define ICREATOR_FACTORY_PLUGIN_LOADER_H

#include <plugin_system/loader/iplugin_loader.h>
#include <factory_plugin/iobject_creator.h>

namespace pf {

///
/// \brief The creator of the plugin loader.
/// \details This interface is required to replace the plug-in loader,
///  if necessary, to obtain additional functionality.
///
class ICreatorFactoryPluginLoader: public IObjectCreator<psys::IPluginLoader>
{
protected:
    ///
    /// \brief Constructor
    /// \param id sub plugin identifier
    ///
    ICreatorFactoryPluginLoader( const QString &id );
public:
    virtual ~ICreatorFactoryPluginLoader();
public:
    virtual psys::IPluginLoader *create() const;
};

}



#endif // ICREATOR_FACTORY_PLUGIN_LOADER_H
