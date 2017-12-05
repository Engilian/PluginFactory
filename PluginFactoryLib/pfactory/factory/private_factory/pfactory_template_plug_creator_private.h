#ifndef PFACTORY_TEMPLATE_PLUG_CREATOR_PRIVATE_H
#define PFACTORY_TEMPLATE_PLUG_CREATOR_PRIVATE_H

#include "pfactory_template_interface_private.h"
#include "pfactory/factory/plugin/iobject_creator.h"

namespace pfactory {

template<typename Interface,  template<class> class ErrorPolicy = PFactoryIgnoreErrorPolicy >

///
/// \brief The object creation class from sub plugin
///
class PFactoryTemplatePlugCreatorPrivate : public PFactoryTemplateInterfacePrivate<Interface, ErrorPolicy>
{
    typedef PFactoryTemplateInterfacePrivate<Interface, ErrorPolicy> Parent;
public:
    PFactoryTemplatePlugCreatorPrivate(IObjectCreator<Interface> *creator):
        Parent( creator->subPluginInfo().interfaceId ),
        _creator( creator ) {}

    PFactoryTemplatePlugCreatorPrivate(ObjectCreator<Interface> creator):
        Parent( creator->subPluginInfo().interfaceId ),
        _creator( creator ) {}
public:
    ~PFactoryTemplatePlugCreatorPrivate(){}
public:

    template<typename... Args>
    ///
    /// \brief Create object
    ///
    Interface *create( Args ...args ) const {

        Interface *obj = nullptr;

        if ( _creator.get() ) {

            try {

                obj = _creator->create( args... );
            } catch ( ... ) {

                // error create obj
                obj = nullptr;
            }
        }

        // If object can't created - generate error
        return obj ? obj : Parent::_policy.createFailed( Parent::_interface );
    }
private:
    std::shared_ptr<IObjectCreator<Interface>>  _creator;
};

}



#endif // PFACTORY_TEMPLATE_PLUG_CREATOR_PRIVATE_H
