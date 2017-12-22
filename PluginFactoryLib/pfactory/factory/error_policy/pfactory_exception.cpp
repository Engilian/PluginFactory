#include "pfactory_exception.h"
using namespace pfactory;

PFactoryException::PFactoryException(const std::string &msg) noexcept:
    _msg( msg )
{

}

PFactoryException::PFactoryException(const QString &msg) noexcept:
    _msg( msg.toStdString () )
{

}

PFactoryException::~PFactoryException() noexcept
{

}

const char *PFactoryException::what() const noexcept
{
    return _msg.c_str();
}
