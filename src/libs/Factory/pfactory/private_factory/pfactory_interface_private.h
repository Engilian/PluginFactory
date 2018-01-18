#ifndef PFACTORY_INTERFACE_PRIVATE_H
#define PFACTORY_INTERFACE_PRIVATE_H

#include <QString>

namespace pf {

class PFactoryInterfacePrivate
{
protected:
    QString         _id;
    QString         _interface;
protected:
    PFactoryInterfacePrivate( const QString &id, const QString &interface );
public:
    virtual ~PFactoryInterfacePrivate();
public:
    QString id() const;
    QString interface() const;
};

}



#endif // PFACTORY_INTERFACE_PRIVATE_H
