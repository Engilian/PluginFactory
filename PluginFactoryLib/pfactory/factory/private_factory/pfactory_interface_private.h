#ifndef PFACTORY_INTERFACE_PRIVATE_H
#define PFACTORY_INTERFACE_PRIVATE_H

#include <QString>

namespace pfactory {

class PFactoryInterfacePrivate
{
protected:
    PFactoryInterfacePrivate( const QString &interface );
public:
    virtual ~PFactoryInterfacePrivate();
public:
    QString interface() const;
protected:
    ///
    /// \brief String interface
    ///
    QString         _interface;
};

}



#endif // PFACTORY_INTERFACE_PRIVATE_H
