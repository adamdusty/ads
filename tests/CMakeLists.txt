include(FetchContent)

FetchContent_Declare(
    unity
    GIT_REPOSITORY  https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG         v2.6.1
    GIT_SHALLOW     TRUE
)
FetchContent_MakeAvailable(unity)

add_executable(darray_tests darray_tests.c)
target_link_libraries(darray_tests ads unity)

add_test(NAME tests COMMAND darray_tests)