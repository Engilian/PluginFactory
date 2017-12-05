#include "pfactory_interface_private.h"
using namespace pfactory;

PFactoryInterfacePrivate::PFactoryInterfacePrivate( const QString &interface ):
    _interface( interface )
{

}

PFactoryInterfacePrivate::~PFactoryInterfacePrivate()
{

}

QString PFactoryInterfacePrivate::interface() const
{
    return _interface;
}
