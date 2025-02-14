#include "ads/darray.h"
#include "tests.h"

void test_darray_push_on_null_ptr() {
    int* integers = NULL;
    int appended  = ads_darrpush(integers, 23);

    ADS_TEST_ASSERT(NULL != integers);
    ADS_TEST_ASSERT(appended == 23);
}

void test_darray_push_to_darray() {
    int64_t* integers = NULL;

    for(int i = 0; i < 16; i++) {
        ads_darrpush(integers, i);
        ADS_TEST_ASSERT(integers != NULL);
    }

    ADS_TEST_ASSERT(integers[0] == 0);
    ADS_TEST_ASSERT(integers[2] == 2);
    ADS_TEST_ASSERT(integers[3] == 3);
    ADS_TEST_ASSERT(integers[4] == 4);
    ADS_TEST_ASSERT(integers[5] == 5);
    ADS_TEST_ASSERT(integers[6] == 6);
    ADS_TEST_ASSERT(integers[7] == 7);
    ADS_TEST_ASSERT(integers[8] == 8);
    ADS_TEST_ASSERT(integers[9] == 9);
    ADS_TEST_ASSERT(integers[10] == 10);
    ADS_TEST_ASSERT(integers[11] == 11);
    ADS_TEST_ASSERT(integers[12] == 12);
    ADS_TEST_ASSERT(integers[13] == 13);
    ADS_TEST_ASSERT(integers[14] == 14);
    ADS_TEST_ASSERT(integers[15] == 15);

    ads_darrfree(integers);
}

void test_darray_darrlen() {
    char* string = NULL;

    ADS_TEST_ASSERT(ads_darrcnt(string) == 0);

    ads_darrpush(string, 'h');
    ads_darrpush(string, 'e');
    ads_darrpush(string, 'l');
    ads_darrpush(string, 'l');
    ads_darrpush(string, 'o');

    ADS_TEST_ASSERT(ads_darrcnt(string) == 5);
    ads_darrfree(string);
}

int main(void) {
    test_darray_push_on_null_ptr();
    test_darray_push_to_darray();
    test_darray_darrlen();
}