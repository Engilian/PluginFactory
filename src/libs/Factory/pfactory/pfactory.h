#ifndef PFACTORY_H
#define PFACTORY_H

#include "private_factory/pfactory_private.h"
#include "private_factory/pfactory_singleton.h"
#include "error_policy/pfactory_ignore_error_policy.h"
#include "error_policy/pfactory_throw_exception_error_policy.h"

namespace pfactory {

template<template<class> class ErrorPolicy >
///
/// \brief Base factory
///
class PBaseFactory: public PFactoryPrivate<ErrorPolicy>,
        public PFactorySingleton<PBaseFactory<ErrorPolicy >>
{
public:
    PBaseFactory():
        PFactoryPrivate<ErrorPolicy> (),
        PFactorySingleton<PBaseFactory<ErrorPolicy> > (){}
public:
    virtual ~PBaseFactory(){}
};


/*
 * For use are the options below
 */

///
/// \brief Plugin factory
/// \details In this implementation, the add, delete, and create
///  errors are not handled
///
using PFactory = PBaseFactory<PFactoryIgnoreErrorPolicy>;

///
/// \brief Plugin factory
/// \details In this implementation, add, delete, and create errors
///  generate exceptions
///
using PFactoryExp = PBaseFactory<PFactoryThrowExceptionErrorPolicy>;
}


#undef TYPE_NAME

#endif // PFACTORY_H
