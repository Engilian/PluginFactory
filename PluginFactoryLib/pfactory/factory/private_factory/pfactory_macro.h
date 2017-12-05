#ifndef PFACTORY_MACRO_H
#define PFACTORY_MACRO_H

#define dFUNC_CHOOSER_7(_f1, _f2, _f3, _f4, _f5, _f6, _f7, N, ... ) N

#define dFUNC_RECOMPOSER(argsWithParentheses)\
    dFUNC_CHOOSER_7 argsWithParentheses

#define dMACRO_CHOOSER(target_, ...)\
    dCHOOSE_FROM_ARG_COUNT(target_, target_##_NO_ARG_EXPANDER __VA_ARGS__ ())

#define dCHOOSE_FROM_ARG_COUNT(arg_, ...) \
    dFUNC_RECOMPOSER((__VA_ARGS__, arg_##_7, arg_##_6, arg_##_5, arg_##_4, arg_##_3, arg_##_2, arg_##_1, ))

/*
 *  Generate params id
 */

#define dPFactoryGenerateId_10(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
    QString( a1 "," a2 "," a3 "," a4 "," a5 "," a6 "," a7 "," a8, "," a9 "," a10 )

#define dPFactoryGenerateId_9(a1, a2, a3, a4, a5, a6, a7, a8, a9 ) \
    QString( a1 "," a2 "," a3 "," a4 "," a5 "," a6 "," a7 "," a8, "," a9 )

#define dPFactoryGenerateId_8(a1, a2, a3, a4, a5, a6, a7, a8 ) \
    QString( a1 "," a2 "," a3 "," a4 "," a5 "," a6 "," a7 "," a8 )

#define dPFactoryGenerateId_7(a1, a2, a3, a4, a5, a6, a7) \
    QString( a1 "," a2 "," a3 "," a4 "," a5 "," a6 "," a7 )

#define dPFactoryGenerateId_6(a1, a2, a3, a4, a5, a6) \
    QString( a1 "," a2 "," a3 "," a4 "," a5 "," a6 )

#define dPFactoryGenerateId_5(a1, a2, a3, a4, a5) \
    QString( a1 "," a2 "," a3 "," a4 "," a5 )

#define dPFactoryGenerateId_4(a1, a2, a3, a4) \
    QString( a1 "," a2 "," a3 "," a4 )

#define dPFactoryGenerateId_3(a1, a2, a3) \
    QString( a1 "," a2 "," a3 )

#define dPFactoryGenerateId_2(a1, a2) \
    QString( a1 "," a2 )

#define dPFactoryGenerateId_1(a1) \
    QString( a1 )

#define dPFactoryGenerateId_0() \
    QString()

#define dPFactoryGenerateId_NO_ARG_EXPANDER() \
    ,,,,,,,dPFactoryGenerateId_0

#define pFactoryGenerateId(...)\
    dMACRO_CHOOSER( dPFactoryGenerateId, __VA_ARGS__)(__VA_ARGS__)

#endif // PFACTORY_MACRO_H
