cmake_minimum_required(VERSION 3.28)
project(
    ads-data-structures
    DESCRIPTION "Library of data structures"
    LANGUAGES C
)

add_library(ads)
target_sources(ads
    PUBLIC
        FILE_SET    ads_headers
        TYPE        HEADERS
        BASE_DIRS   "${CMAKE_CURRENT_BINARY_DIR}/export"
        FILES
            "${CMAKE_CURRENT_BINARY_DIR}/export/ads/export.h"
    PUBLIC
        FILE_SET    ads_headers
        TYPE        HEADERS
        BASE_DIRS   include
        FILES
            "include/ads/darray.h"
            "include/ads/string.h"
    PRIVATE
        src/darray.c
)

include(GenerateExportHeader)
generate_export_header(
    ads
    BASE_NAME ads
    EXPORT_FILE_NAME "export/ads/export.h"
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

set_target_properties(
    ads PROPERTIES
    C_VISIBILITY_PRESET "hidden"
    VISIBILITY_INLINES_HIDDEN YES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

if(BUILD_TESTING)
enable_testing()
add_subdirectory(tests)
endif(BUILD_TESTING)