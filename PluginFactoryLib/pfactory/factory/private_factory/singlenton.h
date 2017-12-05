#ifndef SINGLENTON_H
#define SINGLENTON_H

#include <memory>

template<class T>
///
/// \brief Шаблонная реализация синглтона
///
class Singlenton
{
protected:
    Singlenton(){}
public:
    virtual ~Singlenton(){}
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
std::shared_ptr<T> Singlenton<T>::instObj;

#endif // SINGLENTON_H
