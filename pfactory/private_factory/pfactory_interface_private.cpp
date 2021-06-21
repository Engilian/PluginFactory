#include "pfactory_interface_private.h"
using namespace pf;

PFactoryInterfacePrivate::PFactoryInterfacePrivate(const QString &id , const QString &interface)
  : _id         ( id )
  , _interface  ( interface )
{

}

PFactoryInterfacePrivate::~PFactoryInterfacePrivate()
{

}

QString PFactoryInterfacePrivate::id() const
{
  return _id;
}

QString PFactoryInterfacePrivate::interface() const
{
  return _interface;
}
