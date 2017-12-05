#ifndef IOBJECT_CREATOR_H
#define IOBJECT_CREATOR_H

#include <typeinfo>

#include "pfactory/plugin/isub_plugin.h"


#define TO_STRING(x) typeid(x).name()
#define FACTORY_CREATOR "PluginFactory::IObjectCreator"

namespace pfactory {

template<class Interface>
///
/// \brief Object creator
///
class IObjectCreator: public ISubPlugin
{
protected:
    IObjectCreator( const QString &id,
                    const QString &interface    = TO_STRING( Interface ),
                    const QString &desc         = QString( "Creator ").append ( TO_STRING( Interface ) ) ):
        ISubPlugin( { id, interface, desc } ){}
public:
    virtual ~IObjectCreator(){}
public:
    ///
    /// \brief Create object
    /// \param args argumets
    /// \return object
    ///
    virtual Interface *create() const {

        throw( QString( "Not correct creator " )
                .append ( TO_STRING( this ) )
                .append ( "::" )
                .append ( TO_STRING( Interface ) )
                );
    }
};

template<class Interface>
using ObjectCreator = std::shared_ptr<IObjectCreator<Interface>>;

}

#undef FACTORY_CREATOR
#undef TO_STRING

#endif // IOBJECT_CREATOR_H
