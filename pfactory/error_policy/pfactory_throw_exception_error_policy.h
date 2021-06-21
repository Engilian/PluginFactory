#pragma once
#include "pfactory_exception.h"

namespace pf
{

  template <class Base>
  class PFactoryThrowExceptionErrorPolicy
  {
  public:
    PFactoryThrowExceptionErrorPolicy()
    {

    }
    ~PFactoryThrowExceptionErrorPolicy()
    {

    }
  public:

    ///
    /// \brief Error creating object
    /// \return The object in case of an error
    ///
    Base * createFailed(const QString &type) const
    {
      throw ( PFactoryException(
            QString( "PFactory - can't create object interface \"")
            .append ( typeid (Base).name () )
            .append ( "\" class \"" + type + "\"" )
            )
          );
    }

    ///
    /// \brief Error removing the type from the factory
    ///
    void removeFailed(const QString &type) const
    {
      throw ( PFactoryException(
            QString( "PFactory - can't remove interface ")
            .append ( "\" class \"" + type + "\"" )
            )
          );
    }

    ///
    /// \brief Error adding a type to the factory
    ///
    void duplicateRegistered(const QString &type) const
    {
      throw ( PFactoryException(
            QString( "PFactory - can't register interface \"")
            .append ( typeid (Base).name () )
            .append ( "\" class \"" + type + "\"" )
            )
          );
    }
  };

}
