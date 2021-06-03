#pragma once
#include <QString>
#include <memory>

namespace pf {

///
/// \brief Plugin factory exception
///
class PFactoryException : public std::exception
{
public:
    ///
    /// \brief Constructor
    /// \param msg except string
    ///
    PFactoryException( const std::string & msg ) noexcept;

    ///
    /// \brief Constructor
    /// \param msg except string
    ///
    PFactoryException( const QString &msg ) noexcept;

    virtual ~PFactoryException() noexcept;
public:
    virtual const char* what() const noexcept;
private:
    ///
    /// \brief except string
    ///
    std::string     _msg;
};

}
