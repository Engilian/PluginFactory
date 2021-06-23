#pragma once
#include "pfactory_policy.h"
#include "pfactory_interface_private.h"
#include "pfactory/plugin/object_creator.h"

namespace pf {

  template<typename Interface,  template<class> class ErrorPolicy = PFactoryIgnoreErrorPolicy >
  ///
  /// \brief Template interface for the creator of objects
  ///
  class PFactoryTemplateInterfacePrivate: public PFactoryInterfacePrivate
  {
  protected:
    PFactoryTemplateInterfacePrivate(const QString &id, const QString &interface)
      : PFactoryInterfacePrivate ( id, interface )
      , _policy()
    {

    }
  public:
    virtual ~PFactoryTemplateInterfacePrivate()
    {

    }
  public:
    virtual ErrorPolicy<Interface> policy() const
    {
      return _policy;
    }
  protected:
    ///
    /// \brief Error policy
    ///
    ErrorPolicy<Interface>                      _policy;

  };

}
