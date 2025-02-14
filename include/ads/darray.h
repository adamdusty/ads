#ifndef ADS_DARRAY_H_
#define ADS_DARRAY_H_

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ads_darray_header {
    ptrdiff_t count;    /// Number of elements stored in the array
    ptrdiff_t capacity; /// Number of elements the array has space for
} ads_darray_header;

void* ads_darray_grow(void* arr, size_t element_size);
void ads_darray_free(void* arr);

#define ads_darrheader(ARR) ((ads_darray_header*)(ARR) - 1)

#define ads_darrfree(ARR) ads_darray_free((ARR))

/// Push value onto array. Attempts to grow the array if it doesn't have capacity.
/// Val must be the same type as the dereferenced ARR ptr.
/// @param ARR pointer to array.
/// @param VAL value to push onto the end of the array.
/// @return VAL
#define ads_darrpush(ARR, VAL) ((ads_darrmaybegrow(ARR, 1), (ARR)[ads_darrheader(ARR)->count++] = (VAL)))

/// Get the number of elements in a dynamic array.
/// @param ARR The dynamic array.
/// @return Number of elements in the array as a ptrdiff_t
#define ads_darrcnt(ARR) ((ARR) ? ads_darrheader(ARR)->count : 0)

// If array is null or the new count is greater than the array capacity, grow array, otherwise 0
#define ads_darrmaybegrow(ARR, N)                                                                                      \
    ((!(ARR) || ads_darrheader(ARR)->count + (N) > ads_darrheader(ARR)->capacity)                                      \
         ? ((ARR) = ads_darray_grow(ARR, sizeof(*(ARR))), 0)                                                           \
         : 0)

#ifdef __cplusplus
}
#endif

#endif
