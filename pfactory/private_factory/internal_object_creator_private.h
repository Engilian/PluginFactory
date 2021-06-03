#pragma once
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
    Interface *create() const
    {
        return new Obj();
    }

};

}
