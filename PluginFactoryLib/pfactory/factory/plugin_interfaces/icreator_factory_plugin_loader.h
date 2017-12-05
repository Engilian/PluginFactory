#ifndef ICREATOR_FACTORY_PLUGIN_LOADER_H
#define ICREATOR_FACTORY_PLUGIN_LOADER_H

#include "pfactory/plugin/loader/ifactory_plugin_loader.h"
#include "pfactory/factory/plugin/iobject_creator.h"

namespace pfactory {

///
/// \brief The creator of the plugin loader.
/// \details This interface is required to replace the plug-in loader,
///  if necessary, to obtain additional functionality.
///
class ICreatorFactoryPluginLoader: public IObjectCreator<IFactoryPluginLoader>
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
    virtual IFactoryPluginLoader *create() const;
};

}



#endif // ICREATOR_FACTORY_PLUGIN_LOADER_H
