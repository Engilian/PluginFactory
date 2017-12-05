#ifndef PFACTORY_IGNORE_ERROR_POLICY_H
#define PFACTORY_IGNORE_ERROR_POLICY_H

#include <QString>

namespace pfactory {

template <class Base>
///
/// \brief Factory error ignoring policy
///
class PFactoryIgnoreErrorPolicy
{
public:
    PFactoryIgnoreErrorPolicy(){}
    ~PFactoryIgnoreErrorPolicy(){}
public:

    ///
    /// \brief Error creating object
    /// \return The object in case of an error
    ///
    Base * createFailed(__attribute__((unused)) const QString &type) const
    {
        return nullptr;
    }

    ///
    /// \brief Error removing the type from the factory
    ///
    void removeFailed(__attribute__((unused)) const QString &type) const{}

    ///
    /// \brief Error adding a type to the factory
    ///
    void duplicateRegistered(__attribute__((unused)) const QString &type) const {}
};

}



#endif // PFACTORY_IGNORE_ERROR_POLICY_H
