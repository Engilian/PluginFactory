#ifndef PFACTORY_IGNORE_ERROR_POLICY_H
#define PFACTORY_IGNORE_ERROR_POLICY_H

#include <QString>

namespace pf {

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
    Base * createFailed( const QString &) const
    {
        return nullptr;
    }

    ///
    /// \brief Error removing the type from the factory
    ///
    void removeFailed( const QString &) const{}

    ///
    /// \brief Error adding a type to the factory
    ///
    void duplicateRegistered( const QString &) const {}
};

}



#endif // PFACTORY_IGNORE_ERROR_POLICY_H
