#ifndef IOBJECT_CREATOR_H
#define IOBJECT_CREATOR_H

#include "pfactory/plugin/isub_plugin.h"

#define TO_STRING(x) #x
#define FACTORY_CREATOR "PluginFactory::IObjectCreator"

namespace pfactory {

template<class Interface, typename ...Args>
///
/// \brief Object creator
///
class IObjectCreator: public ISubPlugin
{
protected:
    IObjectCreator( const QString &desc ):
        ISubPlugin( { FACTORY_CREATOR, TO_STRING(Interface), desc } )
    {}
public:
    virtual ~IObjectCreator(){}
public:
    ///
    /// \brief Create object
    /// \param args argumets
    /// \return object
    ///
    virtual Interface *create(Args ...args) const {
        return new Interface( args... );
    }
};

}

#undef FACTORY_CREATOR
#undef TO_STRING

#endif // IOBJECT_CREATOR_H
