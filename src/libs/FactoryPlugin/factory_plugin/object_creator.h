#ifndef OBJECT_CREATOR_H
#define OBJECT_CREATOR_H

#include "iobject_creator.h"

namespace pf {

template<class Interface, class Obj>
class ObjectCreator: public IObjectCreator<Interface>
{
public:
    ObjectCreator( const QString &id,
                 const QString &interface,
                 const QString &desc = "" ):
        IObjectCreator<Interface> ( id, interface , desc ){}

    ~ObjectCreator(){}
public:
    virtual Interface *create() const {

        return new Obj();
    }
};

}



#endif // OBJECT_CREATOR_H
