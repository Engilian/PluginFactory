#ifndef INTERNAL_OBJECT_CREATOR_PRIVATE_H
#define INTERNAL_OBJECT_CREATOR_PRIVATE_H

#include <factory_plugin/iobject_creator.h>

namespace pf {

template<typename Interface, typename Obj>

class InternalObjectCreatorPrivate : public IObjectCreator<Interface>
{
public:
    InternalObjectCreatorPrivate(const QString &id, const QString &interface ):
        IObjectCreator<Interface> (id, interface ) {}
    ~InternalObjectCreatorPrivate(){}
public:

    ///
    /// \brief Create object
    ///
    Interface *create() const {

        return new Obj();
    }

};

}

#endif // INTERNAL_OBJECT_CREATOR_PRIVATE_H
