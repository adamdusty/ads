#ifndef ADS_TESTS_H_
#define ADS_TESTS_H_

#include <assert.h>
#include <stdio.h>

#if __GNUC__
#define ADS_TEST_ASSERT(expr)                                                                                          \
    if(!(expr)) {                                                                                                      \
        fprintf(stderr, "ASSERT FAILED [%s]: %s:%d\n", __func__, __FILE__, __LINE__);                                  \
        __builtin_trap();                                                                                              \
    }

#elif _MSVC_VER
#define ADS_TEST_ASSERT(expr)                                                                                          \
    if(!(expr)) {                                                                                                      \
        printf("ASSERT FAILED:[%s] %s:%d\n", __func__, __FILE__, __LINE__);                                            \
        __debug_break();                                                                                               \
    }
#else
#define ADS_ADS_TEST_ASSERT(expr) assert((expr))
#endif

#endif