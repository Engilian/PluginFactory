#ifndef PFACTORY_PRIVATE_H
#define PFACTORY_PRIVATE_H

#include <QMap>
#include <memory>
#include <QDebug>

#include "pfactory_interface_private.h"
#include "pfactory_template_plug_creator_private.h"
#include "internal_object_creator_private.h"
#include "pfactory_plugin_controller_private.h"

#define PFACTORY_ARGS_NOT_SUPORTED_MESSAGE \
    "Sorry, this version of the library does not support variable" \
    " number of arguments. Perhaps in the future this" \
    " opportunity will appear. " \

#define PFACTORY_ARGS_NOT_SUPORTED() \
    if ( sizeof...(args) > 0 ) { \
    qWarning() << PFACTORY_ARGS_NOT_SUPORTED_MESSAGE << __FUNCTION__; }



namespace pfactory {

template<template<class> class ErrorPolicy = PFactoryIgnoreErrorPolicy >
///
/// \brief Private factory
///
class PFactoryPrivate
{
    using PFInterfacePtr = std::shared_ptr<PFactoryInterfacePrivate>;
public:
    PFactoryPrivate(){

        regInterfaceName<IPFactoryPluginController>( "pfactory::IPFactoryPluginController" );
    }
    ~PFactoryPrivate(){}
public:
    template<typename Interface>
    ///
    /// \brief Register interface name
    /// \param type register type
    ///
    void regInterfaceName( const QString &type ) {

        QString i( typeid (Interface).name () );

        _interfaces[ i ] = type;
    }

    template<typename Interface>
    ///
    /// \brief Unregister interface name
    ///
    void unregInterfaceName() {
        _interfaces.remove ( typeid (Interface).name () );
    }

    template<typename Interface>
    ///
    /// \brief Is Registed interface name
    ///
    bool isRegInterfaceName() const {
        return _interfaces.contains ( typeid ( Interface ).name () );
    }
public:
    template<typename Interface>
    ///
    /// \brief Set default creator id
    /// \param id creator string id
    ///
    void setDefault( const QString &id ) {

        _defaultCreators[ getInterfaceName<Interface>() ] = id;
    }

    template<typename Interface>
    ///
    /// \brief Default creator id
    /// \return string identifier
    ///
    QString defaultCreator() const {

        return _defaultCreators[ getInterfaceName<Interface>() ];
    }
public: // Contains creators
    template<typename Interface>
    bool containsExternalCreator() {

        return !_external[ getInterfaceName<Interface>() ].isEmpty();
    }

    template<typename Interface>
    bool containsExternalCreator( const QString &id ) {

        return _external[ getInterfaceName<Interface>() ].contains( id );
    }

    template<typename Interface>
    bool containsInternalCreator() {

        return !_internal[ getInterfaceName<Interface>() ].isEmpty();
    }

    template<typename Interface>
    bool containsInternalCreator( const QString &id ) {

        return _internal[ getInterfaceName<Interface>() ].contains( id );
    }
public: // Add creators

    template<typename Interface>
    void add( const QString &interface = 0 ) {

        auto i  = interface.isEmpty () ?
                    getInterfaceName<Interface>(): interface;

        if ( !_external.contains ( i ) ) {

            _external[ i ] = QMap<QString, PFInterfacePtr>();
        }

        QMap<QString, PFInterfacePtr> &iMap = _external[ i ];

        for ( auto sub: _controller.creators ( interface ) ) {

            auto creator = std::dynamic_pointer_cast
                    <IObjectCreator<Interface>>( sub );

            if ( creator ) {

                iMap[ sub->subPluginInfo().id ] = creator;
            }
        }

        if ( !_defaultCreators.contains( i ) ) {

            _defaultCreators[ i ] = iMap.first ()->interface ();
        }
    }

    template<typename Interface, typename Obj>
    void add( const QString &interface = "", const QString &obj = "" ) {

        auto i  = interface.isEmpty () ?
                    getInterfaceName<Interface>(): interface;

        auto o  = obj.isEmpty () ?
                    getInterfaceName<Obj>(): obj;

        if ( !containsInternalCreator<Interface>( obj ) ) {

            if ( defaultCreator<Interface>().isEmpty() ) {
                setDefault<Interface>( o );
            }

            PFInterfacePtr ptr(
                        new PFactoryTemplatePlugCreatorPrivate<Interface, ErrorPolicy>
                        ( new InternalObjectCreatorPrivate<Interface, Obj>( o, i ) )
                        );

            _internal[ i ][ o ] = ptr;
        }
        else {

            ErrorPolicy<Interface>().duplicateRegistered( obj );
        }
    }

public:

    template<typename Interface>
    ///
    /// \brief Create object
    /// \param args arguments
    /// \return object
    ///
    Interface *create() {

        return createByInterface<Interface>( getInterfaceName<Interface>() );
    }

    template<typename Interface>
    ///
    /// \brief Create object
    /// \param args arguments
    /// \return object
    ///
    Interface *create( const QString &classId ) {

        return createByClassId<Interface>( classId );
    }

    template<typename Interface, typename... Args>
    ///
    /// \brief Create object
    /// \param interface string interface object
    /// \param args drgumets
    /// \return object
    ///
    Interface *createByInterface( const QString &interface, Args ...args ) {

        QString defaultCreator = _defaultCreators[ interface ];

        if ( _external[ interface ].contains( defaultCreator ) ) {

            return createExternalByInterface<Interface, Args...>( interface, args... );
        }
        else if ( _internal[ interface ].contains( defaultCreator ) ) {

            return createInternalByInterface<Interface, Args...>( interface, args... );
        }
        else {

            return ErrorPolicy<Interface>().createFailed( interface );
        }
    }

    template<typename Interface, typename... Args>
    ///
    /// \brief Create internal object
    /// \param interface string interface
    /// \param args args
    /// \return object
    ///
    Interface *createExternalByInterface( const QString &interface, Args ...args ) {

        QString defaultCreatorName  = _defaultCreators[ interface ];
        return createExternalByClassId<Interface, Args...>( interface, defaultCreatorName, args... );
    }

    template<typename Interface, typename... Args>
    ///
    /// \brief Create internal object
    /// \param interface string interface
    /// \param args args
    /// \return object
    ///
    Interface *createInternalByInterface( const QString &interface, Args ...args ) {

        QString defaultCreatorName  = _defaultCreators[ interface ];
        return createInternalByClassId<Interface, Args...>( interface, defaultCreatorName, args... );
    }

    template<typename Interface, typename... Args>
    ///
    /// \brief Create external object
    /// \param interface string interface
    /// \param classId string class identifier
    /// \param args args
    /// \return object
    ///
    Interface *createByClassId( const QString &classId, Args ...args ) {

        if ( containsInternalCreator<Interface>( classId ) ) {

            return createInternalByClassId<Interface, Args...>( getInterfaceName<Interface>(), classId, args... );
        }
        else if ( containsExternalCreator<Interface>( classId ) ) {

            return createExternalByClassId<Interface, Args...>( getInterfaceName<Interface>(), classId, args... );
        }
        else {

            return ErrorPolicy<Interface>().createFailed( classId );
        }
    }


    template<typename Interface, typename... Args>
    ///
    /// \brief Create external object
    /// \param interface string interface
    /// \param classId string class identifier
    /// \param args args
    /// \return object
    ///
    Interface *createExternalByClassId( const QString &interface, const QString &classId, __attribute__((unused)) Args ...args ) {

        auto creators               = _external[ interface ];

        PFACTORY_ARGS_NOT_SUPORTED();

        if ( creators.contains( classId ) ) {

            return std::dynamic_pointer_cast<PFactoryTemplatePlugCreatorPrivate
                    <Interface, ErrorPolicy>>( creators[ classId ] )->create();
        }

        return ErrorPolicy<Interface>().createFailed( classId );
    }

    template<typename Interface, typename... Args>
    ///
    /// \brief Create internal object
    /// \param interface string interface
    /// \param classId string interface
    /// \param args args
    /// \return object
    ///
    Interface *createInternalByClassId( const QString &interface, const QString &classId, __attribute__((unused)) Args ...args ) {

        auto creators               = _internal[ interface ];

        PFACTORY_ARGS_NOT_SUPORTED();

        if ( creators.contains( classId ) ) {

            return std::dynamic_pointer_cast<PFactoryTemplatePlugCreatorPrivate
                    <Interface, ErrorPolicy>>( creators[ classId ] )->create();
        }

        return ErrorPolicy<Interface>().createFailed( classId );
    }
public:
    template<typename Interface>
    QString getInterfaceName() const {

        const QString id = typeid ( Interface ).name ();
        return _interfaces.contains ( id ) ? _interfaces[ id ] : id;
    }
private:
    PFactoryPluginControllerPrivate             _controller;
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

}

#undef PFACTORY_ARGS_NOT_SUPORTED
#undef PFACTORY_ARGS_NOT_SUPORTED_MESSAGE



#endif // PFACTORY_PRIVATE_H
