#pragma once
#include <QString>
#include <typeinfo>

namespace pf {

template<class T>
///
/// \brief Singlton
///
class PFactorySingleton
{
    static T        *_d;
protected:
    PFactorySingleton() {
    }
public:
    virtual ~PFactorySingleton(){}
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

};

template<class T>
T *PFactorySingleton<T>::_d = nullptr;

}
