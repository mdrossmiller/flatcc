#ifndef PSTDALIGN_H
#define PSTDALIGN_H

/*
 * NOTE: aligned_alloc is defined via paligned_alloc.h
 * and requires aligned_free to be fully portable although
 * free also works on C11 and platforms with posix_memalign.
 */

#ifndef __alignas_is_defined
#ifndef __cplusplus

#if (defined(__GNUC__) && (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCH__) < 447) || \
    defined(__IBMC__)
#undef PORTABLE_C11_STDALIGN_MISSING
#define PORTABLE_C11_STDALIGN_MISSING
#endif

#if (defined(__STDC__) && __STDC__ && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) && \
    !defined(PORTABLE_C11_STDALIGN_MISSING)
/* C11 or newer */
#include <stdalign.h>

#else

#if defined(__GNUC__) || defined (__IBMC__) || defined(__clang__)
#define _Alignas(t) __attribute__((__aligned__(t)))
#define _Alignof(t) __alignof__(t)
#elif defined(_MSC_VER)
#define _Alignas(t) __declspec (align(t))
#define _Alignof(t) __alignof(t)

#else
#error please update pstdalign.h with support for current compiler
#endif

#endif /* __STDC__ */

#define alignas _Alignas
#define alignof _Alignof

#define __alignas_is_defined 1
#define __alignof_is_defined 1

#endif /* __cplusplus */
#endif /* __alignas__is_defined */

#include "paligned_alloc.h"

#endif /* PSTDALIGN_H */
