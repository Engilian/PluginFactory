#ifndef PFACTORY_TEMPLATE_INTERFACE_PRIVATE_H
#define PFACTORY_TEMPLATE_INTERFACE_PRIVATE_H

#include "pfactory_interface_private.h"
#include <factory_plugin/iobject_creator.h>
#include "pfactory/error_policy/pfactory_ignore_error_policy.h"

namespace pfactory {

template<typename Interface,  template<class> class ErrorPolicy = PFactoryIgnoreErrorPolicy >
///
/// \brief Template interface for the creator of objects
///
class PFactoryTemplateInterfacePrivate: public PFactoryInterfacePrivate
{
protected:
    PFactoryTemplateInterfacePrivate( const QString &id, const QString &interface ):
        PFactoryInterfacePrivate ( id, interface ),
        _policy() {}
public:
    virtual ~PFactoryTemplateInterfacePrivate(){}
public:
    virtual ErrorPolicy<Interface> policy() const {
        return _policy;
    }
protected:
    ///
    /// \brief Error policy
    ///
    ErrorPolicy<Interface>                      _policy;

};

}



#endif // PFACTORY_TEMPLATE_INTERFACE_PRIVATE_H
