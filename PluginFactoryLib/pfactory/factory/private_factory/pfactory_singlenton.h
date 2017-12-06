#ifndef PLUGIN_FACTORY_SINGLENTON_H
#define PLUGIN_FACTORY_SINGLENTON_H

#include <memory>

namespace pfactory {

template<class T>
///
/// \brief Шаблонная реализация синглтона
///
class PFactorySinglenton
{
protected:
    PFactorySinglenton(){}
public:
    virtual ~PFactorySinglenton(){}
public:
    ///
    /// \brief Получить глобальный экземпляр
    ///
    static std::shared_ptr<T> instance() {
        if ( !instObj.get() ) instObj = std::make_shared<T>();
        return instObj;
    }

    ///
    /// \brief Удалить глобальный экземпляр
    ///
    static void clearInstance() {
        instObj.reset();
    }
private:
    ///
    /// \brief Глобальный экземпляр
    ///
    static std::shared_ptr<T> instObj;
};

template<class T>
std::shared_ptr<T> PFactorySinglenton<T>::instObj;

}



#endif // PLUGIN_FACTORY_SINGLENTON_H
