#pragma once
#include <QString>
#include <typeinfo>
#include "error_policy.h"

#define TO_STRING(x) typeid(x).name()

namespace pf
{
  class ICreator
  {
  public:
    ICreator()
    {
    }
    virtual ~ICreator()
    {
    }
  public:
    virtual QString id() const = 0;
    virtual QString interface() const = 0;
  };
  using Creator = std::shared_ptr<ICreator>;

  template<class Interface>
  ///
  /// \brief Object creator
  ///
  class IObjectCreator
      : public pf::ICreator
  {
  protected:
    IObjectCreator()
      : pf::ICreator()
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


  template<class Interface, class Obj>
  class ObjectCreator: public IObjectCreator<Interface>
  {
    QString m_id, m_interface;
  public:
    ObjectCreator(const QString &id,
                  const QString &interface)
      : IObjectCreator<Interface> ()
      , m_id( id )
      , m_interface( interface )
    {

    }
    ~ObjectCreator() override
    {

    }
  public:
    virtual Interface *create() const
    {
      return new Obj();
    }

    // ICreator interface
  public:
    virtual QString id() const
    {
      return m_id;
    }
    virtual QString interface() const
    {
      return m_interface;
    }
  };

  template<class Interface>
  class ObjectCreatorDecorator
      : public IObjectCreator<Interface>
  {
  public:
    using IObjectCreatorPtr = std::shared_ptr<IObjectCreator<Interface>>;
  private:
    IObjectCreatorPtr m_creator;
  public:
    ObjectCreatorDecorator(const IObjectCreatorPtr &creator)
      : IObjectCreator<Interface> ()
      , m_creator( creator )
    {

    }
    ~ObjectCreatorDecorator() override
    {
      delete m_creator;
    }
  public:
    virtual Interface *create() const
    {
      return m_creator->create();
    }

    // ICreator interface
  public:
    virtual QString id() const
    {
      return m_creator->id();
    }
    virtual QString interface() const
    {
      return m_creator->interface();
    }
  };

  template<typename Interface, class Obj,  template<class> class ErrorPolicy = PFactoryIgnoreErrorPolicy>
  class PolicyObjectCreator: public IObjectCreator<Interface>
  {
    QString m_id, m_interface;
  public:
    PolicyObjectCreator(const QString &id,
                  const QString &interface)
      : IObjectCreator<Interface> ()
      , m_id( id )
      , m_interface( interface )
    {

    }
    ~PolicyObjectCreator() override
    {

    }
  public:
    virtual Interface *create() const
    {
      try {
        return new Obj();
      } catch (...) {
        return ErrorPolicy<Interface>().createFailed( m_id );
      }
    }

    // ICreator interface
  public:
    virtual QString id() const
    {
      return m_id;
    }
    virtual QString interface() const
    {
      return m_interface;
    }
  };

  template<typename Interface,  template<class> class ErrorPolicy = PFactoryIgnoreErrorPolicy>
  class PolicyObjectCreatorDecorator
      : public IObjectCreator<Interface>
  {
  public:
    using IObjectCreatorPtr = std::shared_ptr<IObjectCreator<Interface>>;
  private:
    IObjectCreatorPtr m_creator;
  public:
    PolicyObjectCreatorDecorator(const IObjectCreatorPtr &creator)
      : IObjectCreator<Interface> ()
      , m_creator( creator )
    {

    }
    ~PolicyObjectCreatorDecorator() override
    {
    }
  public:
    virtual Interface *create() const
    {
      try {
        return m_creator->create();
      } catch (...) {
        return ErrorPolicy<Interface>().createFailed( m_creator->id() );
      }
    }

    // ICreator interface
  public:
    virtual QString id() const
    {
      return m_creator->id();
    }
    virtual QString interface() const
    {
      return m_creator->interface();
    }
  };
}
