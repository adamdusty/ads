add_executable(darray_tests darray_tests.c)
target_link_libraries(darray_tests ads)

add_test(NAME tests COMMAND darray_tests)