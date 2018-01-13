#ifndef PLUGIN_FACTORY_SINGLETON_H
#define PLUGIN_FACTORY_SINGLETON_H

#include <QString>
#include <typeinfo>

namespace pfactory {

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
    static T *instance() {

        _d = _d ? _d : new T();
        return _d;
    }

    ///
    /// \brief Free global instance
    ///
    static void destroy() {

        if ( _d ) delete _d;
        _d = nullptr;
    }

};

template<class T>
T *PFactorySingleton<T>::_d = nullptr;

}



#endif // PLUGIN_FACTORY_SINGLETON_H
