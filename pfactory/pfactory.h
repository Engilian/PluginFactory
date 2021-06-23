#pragma once
#include <QMap>
#include <memory>
#include <typeinfo>

#include "private_factory/pfactory_policy.h"
#include "private_factory/pfactory_interface_private.h"
#include "private_factory/pfactory_template_plug_creator_private.h"
#include "private_factory/pfactory_plugin_controller_private.h"

namespace pf
{
  template<class T>
  ///
  /// \brief Singlton
  ///
  class PFactorySingleton
  {

  protected:
    PFactorySingleton() = default;
  public:
    virtual ~PFactorySingleton() = default;
  public:
    ///
    /// \brief Global instance
    ///
    static T *instance()
    {
      _d = _d ? _d : new T();
      return _d;
    }

    ///
    /// \brief Global instance
    ///
    static T *inst()
    {
      return instance ();
    }

    ///
    /// \brief Free global instance
    ///
    static void destroy()
    {
      if ( _d ) delete _d;
      _d = nullptr;
    }

  private:
    static T *_d;
  };

  template<class T>
  T *PFactorySingleton<T>::_d = nullptr;

  template<template<class> class ErrorPolicy = PFactoryIgnoreErrorPolicy >
  ///
  /// \brief Private factory
  ///
  class PFactory
      : public PFactorySingleton<PFactory<ErrorPolicy >>
  {
  public:
    enum class Type
    {
      Internal, External, Any
    };

  private:
    using PFInterfacePtr = std::shared_ptr<PFactoryInterfacePrivate>;
  public:
    PFactory()
      : _controller ( std::make_shared<PFactoryPluginControllerPrivate>() )
    {
    }
    virtual ~PFactory()
    {
      _external.clear ();
      _internal.clear ();
    }
  public:
    ///
    /// \brief Registed interfaces list
    ///
    QStringList interfaces() const
    {
      return _interfaces.values ();
    }

    template<typename Interface>
    ///
    /// \brief Set default creator id
    /// \param id creator string id
    ///
    void setDefault(const QString &id)
    {
      _defaultCreators[ getInterfaceName<Interface>() ] = id;
    }

    template<typename Interface>
    ///
    /// \brief Default creator id
    /// \return string identifier
    ///
    QString defaultCreator() const
    {
      return _defaultCreators[ getInterfaceName<Interface>() ];
    }
  public: // Contains creators

    template<typename Interface>
    bool contains(Type type = Type::Any) const
    {
      switch ( type ) {
        case Type::Internal:
          return !_internal[ getInterfaceName<Interface>() ].isEmpty();
        case Type::External:
          return !_external[ getInterfaceName<Interface>() ].isEmpty();
        default:
          return !_internal[ getInterfaceName<Interface>() ].isEmpty()
              || !_external[ getInterfaceName<Interface>() ].isEmpty();
      }
    }

    template<typename Interface>
    bool contains(const QString &id, Type type = Type::Any) const
    {
      switch ( type ) {
        case Type::Internal:
          return _internal[ getInterfaceName<Interface>() ].contains( id );
        case Type::External:
          return _external[ getInterfaceName<Interface>() ].contains( id );
        default:
          return _internal[ getInterfaceName<Interface>() ].contains( id )
              || _external[ getInterfaceName<Interface>() ].contains( id );
      }
    }
  public: // Add creators

    template<typename Interface>
    ///
    /// \brief Add the interface to the factory
    /// \param interface interface name
    ///
    void add(const QString &interface = 0)
    {
      if ( !interface.isEmpty () ) {
        _interfaces[ QString( typeid (Interface).name () ) ] = interface;
      }

      auto interfaceName  = interface.isEmpty () ?
            getInterfaceName<Interface>(): interface;

      if ( !_external.contains ( interfaceName ) ) {

        _external[ interfaceName ] = QMap<QString, PFInterfacePtr>();
        loadCreators<Interface>( interfaceName );
      }
    }

    template<typename Interface, typename Obj>
    ///
    /// \brief Add interface and implementation to the factory
    /// \param interface interface name
    /// \param obj implimentation name
    ///
    void add(const QString &interface = "", const QString &obj = "")
    {
      if ( !interface.isEmpty () ) {
        _interfaces[ QString( typeid (Interface).name () ) ] = interface;
      }

      if ( !obj.isEmpty () ) {
        _interfaces[ QString( typeid (Obj).name () ) ] = obj;
      }

      auto interfaceName  = interface.isEmpty () ?
            getInterfaceName<Interface>(): interface;

      auto objectClassName  = obj.isEmpty () ?
            getInterfaceName<Obj>(): obj;

      if ( !contains<Interface>( obj, Type::Internal ) ) {

        if ( defaultCreator<Interface>().isEmpty() ) {
          setDefault<Interface>( objectClassName );
        }

        _internal[ interfaceName ][ objectClassName ] =
            std::make_shared<PFactoryTemplatePlugCreatorPrivate<Interface, ErrorPolicy>>
                ( new ObjectCreator<Interface, Obj>( objectClassName, interfaceName ) );

        if ( !_external.contains ( interfaceName ) )  loadCreators<Interface>( interfaceName );
      }
      else {

        ErrorPolicy<Interface>().duplicateRegistered( obj );
      }
    }

    template<typename Interface>
    ///
    /// \brief Get a list of interface implementations.
    /// \return list of implementation names
    ///
    QStringList creatorNames() const
    {
      auto interfaceName = getInterfaceName<Interface>();

      QStringList result = _internal[ interfaceName ].keys();
      result.append ( _external[interfaceName].keys() );

      return result;
    }

    ///
    /// \brief Get a list of interface implementations.
    /// \param interface interface name
    /// \return list of implementation names
    ///
    QStringList creatorNames(const QString &interface) const
    {
      QStringList result = _internal[ interface ].keys();
      result.append ( _external[interface].keys() );

      return result;
    }

  public: // Create objects

    template<typename Interface>
    ///
    /// \brief Create object
    /// \param args arguments
    /// \return object
    ///
    Interface *create(Type type = Type::Any) const
    {
      auto interface          = getInterfaceName<Interface>();
      QString defaultCreator  = _defaultCreators[ interface ];
      switch ( type ) {
        case Type::Internal:
          if ( _internal[ interface ].contains( defaultCreator ) )
            return createInternalByInterface<Interface>( interface );
          if ( _internal.contains ( interface ) )
            return createInternalByInterface<Interface>( interface );
          break;

        case Type::External:
          if ( _external[ interface ].contains( defaultCreator ) )
            return createExternalByInterface<Interface>( interface );
          if ( _external.contains ( interface ) )
            return createExternalByInterface<Interface>( interface );
          break;

        default:
          if ( _internal[ interface ].contains( defaultCreator ) )
            return createInternalByInterface<Interface>( interface );
          if ( _external[ interface ].contains( defaultCreator ) )
            return createExternalByInterface<Interface>( interface );

          if ( _internal.contains ( interface ) )
            return createInternalByInterface<Interface>( interface );
          if ( _external.contains ( interface ) )
            return createExternalByInterface<Interface>( interface );
          break;
      }

      return ErrorPolicy<Interface>().createFailed( interface );
    }

    template<typename Interface>
    ///
    /// \brief Create object
    /// \param args arguments
    /// \return object
    ///
    Interface *create(const QString &classId, Type type = Type::Any) const
    {
      switch ( type ) {
        case Type::Internal:
          return createInternalByClassId<Interface>( getInterfaceName<Interface>(), classId );

        case Type::External:
          return createExternalByClassId<Interface>( getInterfaceName<Interface>(), classId );

        default:
          if ( contains<Interface>( classId, Type::Internal ) )
            return createInternalByClassId<Interface>( getInterfaceName<Interface>(), classId );

          if ( contains<Interface>( classId, Type::External ) )
            return createExternalByClassId<Interface>( getInterfaceName<Interface>(), classId );
          break;
      }

      return ErrorPolicy<Interface>().createFailed( classId );
    }

    template<typename Interface, typename DefaultClass>
    ///
    /// \brief create
    /// \return
    ///
    Interface *create() const
    {
      Interface *obj = nullptr;

      try {
        obj = create<Interface>();
      } catch ( ... ) { }

      return obj ? obj: new DefaultClass();
    }
  public:
    ///
    /// \brief Get the controller working with plugins.
    /// \return plugincontroller
    ///
    PFactoryPluginController controller() const
    {
      return _controller;
    }

    // --------------------- PRIVATE METHODS ------------------------------
  private:
    template<typename Interface>
    QString getInterfaceName() const
    {
      const QString id = typeid ( Interface ).name ();
      return _interfaces.contains ( id ) ? _interfaces[ id ] : id;
    }

    template<typename Interface>
    ///
    /// \brief Register interface name
    /// \param type register type
    ///
    void regInterfaceName(const QString &type)
    {
      _interfaces[ QString ( typeid (Interface).name () ) ] = type;
    }

    template<typename Interface>
    ///
    /// \brief Unregister interface name
    ///
    void unregInterfaceName()
    {
      _interfaces.remove ( typeid (Interface).name () );
    }

    template<typename Interface>
    ///
    /// \brief Is Registed interface name
    ///
    bool isRegInterfaceName() const
    {
      return _interfaces.contains ( typeid ( Interface ).name () );
    }
  private:

    template<typename Interface>
    ///
    /// \brief Create internal object
    /// \param interface string interface
    /// \param args args
    /// \return object
    ///
    Interface *createExternalByInterface(const QString &interface) const
    {
      QString defaultCreatorName  = _defaultCreators[ interface ];

      try {

        auto *obj = createExternalByClassId<Interface>( interface, defaultCreatorName );
        if ( obj ) return obj;

      } catch (...) { }

      for ( auto &creatorName: _external[ interface ].keys() )
      {
        try {

          auto *obj = createExternalByClassId<Interface>( interface, creatorName );
          if ( obj ) return obj;

        } catch (...) { }
      }

      return ErrorPolicy<Interface>().createFailed( interface );
    }

    template<typename Interface>
    ///
    /// \brief Create internal object
    /// \param interface string interface
    /// \param args args
    /// \return object
    ///
    Interface *createInternalByInterface(const QString &interface) const
    {
      QString defaultCreatorName  = _defaultCreators[ interface ];

      try {

        auto *obj = createInternalByClassId<Interface>( interface, defaultCreatorName );
        if ( obj ) return obj;

      } catch (...) { }

      for ( auto &creatorName: _internal[ interface ].keys() )
      {
        try {

          auto *obj = createInternalByClassId<Interface>( interface, creatorName );
          if ( obj ) return obj;

        } catch (...) { }
      }

      return ErrorPolicy<Interface>().createFailed( interface );
    }

    template<typename Interface>
    ///
    /// \brief Create external object
    /// \param interface string interface
    /// \param classId string class identifier
    /// \param args args
    /// \return object
    ///
    Interface *createExternalByClassId(const QString &interface, const QString &classId) const
    {
      auto creators = _external[ interface ];

      if ( creators.contains( classId ) ) {

        return std::dynamic_pointer_cast<PFactoryTemplatePlugCreatorPrivate
            <Interface, ErrorPolicy>>( creators[ classId ] )->create();
      }

      return ErrorPolicy<Interface>().createFailed( classId );
    }

    template<typename Interface>
    ///
    /// \brief Create internal object
    /// \param interface string interface
    /// \param classId string interface
    /// \param args args
    /// \return object
    ///
    Interface *createInternalByClassId(const QString &interface, const QString &classId) const
    {
      auto creators = _internal[ interface ];

      if ( creators.contains( classId ) ) {

        return std::dynamic_pointer_cast<PFactoryTemplatePlugCreatorPrivate
            <Interface, ErrorPolicy>>( creators[ classId ] )->create();
      }

      return ErrorPolicy<Interface>().createFailed( classId );
    }
  private:
    template<typename Interface>
    void loadCreators(const QString &interface)
    {
      QMap<QString, PFInterfacePtr> &creators = _external[ interface ];
      for ( auto sub: _controller->creators ( interface ) ) {

        auto objCreator = std::dynamic_pointer_cast
            <IObjectCreator<Interface>>( sub );

        if ( objCreator ) {

          creators[ sub->subPluginInfo().id ] =
              PFInterfacePtr (
                new PFactoryTemplatePlugCreatorPrivate
                <Interface, ErrorPolicy>( objCreator )
                );
        }
        else {
          fprintf ( stderr, "Error cast creator %s",
                    sub->subPluginInfo ().id.toStdString ().c_str () );
        }
      }
    }

    // --------------------- PRIVATE VARIABLES ------------------------------
  private:
    PFactoryPluginController                    _controller;
  private:
    ///
    /// \brief Prototype interface name, interface name
    ///
    QMap<QString, QString>                      _interfaces;

    ///
    /// \brief Interface - default creator name
    ///
    QMap<QString, QString>                      _defaultCreators;
  private:
    ///
    /// \brief External creators
    /// \details QMap<Obj interface, QMap<Sub plugin id, Creator >>
    ///
    QMap<QString, QMap<QString, PFInterfacePtr>> _external;

    ///
    /// \brief Internal creators
    /// \details QMap<Obj interface, QMap<Class id, Creator >>
    ///
    QMap<QString, QMap<QString, PFInterfacePtr>> _internal;

  };


  /*
 * For use are the options below
 */

  ///
  /// \brief Plugin factory
  /// \details In this implementation, the add, delete, and create
  ///  errors are not handled
  ///
  using Factory = PFactory<PFactoryIgnoreErrorPolicy>;

  ///
  /// \brief Plugin factory
  /// \details In this implementation, add, delete, and create errors
  ///  generate exceptions
  ///
  using FactoryExp = PFactory<PFactoryThrowExceptionErrorPolicy>;
}

#undef TYPE_NAME
