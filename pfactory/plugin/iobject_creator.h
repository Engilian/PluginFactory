#pragma once
#include <typeinfo>
#include <pfactory/plugin/psys/isub_plugin.h>

#define TO_STRING(x) typeid(x).name()

namespace pf {

  template<class Interface>
  ///
  /// \brief Object creator
  ///
  class IObjectCreator: public psys::ISubPlugin
  {
  protected:
    IObjectCreator(const QString &id,
                   const QString &interface = TO_STRING( Interface ))
      : psys::ISubPlugin( { id, interface } )
    {

    }
    IObjectCreator( const psys::SubPluginInfo &info )
      : psys::ISubPlugin( info )
    {

    }
  public:
    virtual ~IObjectCreator()
    {

    }
  public:
    ///
    /// \brief Create object
    /// \param args argumets
    /// \return object
    ///
    virtual Interface *create() const
    {

      throw( QString( "Not correct creator " )
          .append ( TO_STRING( this ) )
          .append ( "::" )
          .append ( TO_STRING( Interface ) )
          );
    }
  };

  template<class Interface>
  using ObjCreator = std::shared_ptr<IObjectCreator<Interface>>;
}

#undef TO_STRING
