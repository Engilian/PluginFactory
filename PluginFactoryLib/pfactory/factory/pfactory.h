#ifndef PFACTORY_H
#define PFACTORY_H

#include <QString>
#include <iostream>


#include "private_factory/pfactory_singlenton.h"
#include "error_policy/pfactory_ignore_error_policy.h"
#include "error_policy/pfactory_throw_exception_error_policy.h"

#include "private_factory/pfactory_macro.h"

#define TYPE_NAME(x) #x


namespace pfactory {

class PFactory: public PFactorySinglenton<PFactory>
{
public:
    PFactory();
public:
    virtual ~PFactory();
public: // Reg type

    template<typename Interface, typename ...Args>
    ///
    /// \brief Register interface type
    /// \param type interface type identifier
    /// \param args string
    ///
    void registerType( const QString &type, const QString &args = "" ) {

        std::cout << type.toStdString ()
                  << " create("
                  << args.toStdString ()
                  << ") const"
                  << std::endl;
    }

public: // Unreg type

    template<typename Interface, typename ...Args>
    ///
    /// \brief unregisterType
    /// \param type interface type identifier
    ///
    void unregisterType( const QString &type ) {

    }

    template<typename Interface, typename ...Args>
    void unregisterType() {

        QString type( TYPE_NAME( Interface) );
        unregisterType<Interface, Args...>( type );
    }
public:

public: // Create objects

    template<typename Interface, typename ...Args>
    ///
    /// \brief create
    /// \param type interface type identifier
    /// \return
    ///
    Interface *create( const QString &type ) {

        return nullptr;
    }

    template<typename Interface, typename ...Args>
    Interface *create() {

        QString type( TYPE_NAME( Interface) );
        return  create<Interface, Args...>( type );
    }
public: // Create objects ptr

    template<typename Interface, typename ...Args>
    ///
    /// \brief create
    /// \param type interface type identifier
    /// \return object shared ptr
    ///
    Interface *createPtr( const QString &type ) {
        return std::shared_ptr<Interface>( create<Interface, Args...>( type ) );
    }

    template<typename Interface, typename ...Args>
    ///
    /// \brief Create object ptr
    /// \return object shared ptr
    ///
    Interface *createPtr() {
        return std::shared_ptr<Interface>( create<Interface, Args...>() );
    }

};

}



#undef TYPE_NAME

#endif // PFACTORY_H
