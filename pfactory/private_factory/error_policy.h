#pragma once
#include <QString>
#include <typeinfo>

namespace pf
{
  ///
  /// \brief Plugin factory exception
  ///
  class PFactoryException
      : public std::exception
  {
  public:
    ///
    /// \brief Constructor
    /// \param msg except string
    ///
    PFactoryException(const std::string & msg) noexcept
      : std::exception()
      , _msg( msg )
    {
    }

    ///
    /// \brief Constructor
    /// \param msg except string
    ///
    PFactoryException(const QString &msg) noexcept
      : std::exception()
      , _msg( msg.toStdString() )
    {
    }

    virtual ~PFactoryException() noexcept
    {
    }
  public:
    virtual const char* what() const noexcept
    {
      return _msg.c_str();
    }

  private:
    ///
    /// \brief except string
    ///
    std::string     _msg;
  };

  template <class Base>
  ///
  /// \brief Factory error ignoring policy
  ///
  class PFactoryIgnoreErrorPolicy
  {
  public:
    PFactoryIgnoreErrorPolicy()
    {

    }
    ~PFactoryIgnoreErrorPolicy()
    {

    }
  public:

    ///
    /// \brief Error creating object
    /// \return The object in case of an error
    ///
    Base * createFailed( const QString &) const
    {
      return nullptr;
    }
  };

  template <class Base>
  class PFactoryThrowExceptionErrorPolicy
  {
  public:
    PFactoryThrowExceptionErrorPolicy()
    {

    }
    ~PFactoryThrowExceptionErrorPolicy()
    {

    }
  public:

    ///
    /// \brief Error creating object
    /// \return The object in case of an error
    ///
    Base * createFailed(const QString &type) const
    {
      throw ( PFactoryException(
            QString( "PFactory - can't create object interface \"")
            .append ( typeid (Base).name () )
            .append ( "\" class \"" + type + "\"" )
            )
          );
    }
  };
}
