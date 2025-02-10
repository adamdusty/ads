#ifndef ADS_DARRAY_H_
#define ADS_DARRAY_H_

#include "ads/export.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ads_darray_header {
    ptrdiff_t length;
    ptrdiff_t capacity;
} ads_darray_header;

#define ads_arrpush(ARR, VAL) ads_darray_push(ARR, VAL)

ADS_EXPORT void* ads_darray_push(void* array, void* value);

#ifdef __cplusplus
}
#endif

#endif