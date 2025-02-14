#include "ads/darray.h"
#include "ads/alloc.h"

void* ads_darray_grow(void* arr, size_t element_size) {
    // If `arr` is null, we assume it is an array that hasn't been allocated yet
    if(NULL == arr) {
        ads_darray_header header = {0};
        header.count             = 0;
        header.capacity          = 8;

        void* mem = ads_malloc(sizeof(ads_darray_header) + (element_size * header.capacity));
        memset(mem, 0, sizeof(ads_darray_header) + (element_size * header.capacity));
        memcpy(mem, &header, sizeof(ads_darray_header));

        arr = (char*)mem + sizeof(ads_darray_header);
        return arr;
    }

    ads_darray_header* header = ads_darrheader(arr);

    size_t new_cap = header->capacity * 2;

    char* new_mem = ads_malloc(sizeof(ads_darray_header) + (element_size * new_cap));
    if(NULL == new_mem) {
        return arr;
    }

    memset(new_mem, 0, sizeof(ads_darray_header) + (element_size * new_cap));
    memcpy(new_mem, header, sizeof(ads_darray_header) + (element_size * header->capacity));
    header           = (ads_darray_header*)new_mem;
    header->capacity = new_cap;

    void* new_arr = (char*)new_mem + sizeof(ads_darray_header);

    ads_free(ads_darrheader(arr));

    return new_arr;
}

void ads_darray_free(void* arr) {
    ads_free(ads_darrheader(arr));
}
