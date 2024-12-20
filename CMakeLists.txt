cmake_minimum_required(VERSION 3.10)

project(PepGE VERSION 0.0.0)

add_subdirectory(ext/SDL)
add_subdirectory(ext/Core)

add_library(
    "${PROJECT_NAME}_LIB"
    "src/PepGE.c" "include/PepGE.h" 
    "src/KeyInMgr.c" "include/KeyInMgr.h"
)

target_include_directories(${PROJECT_NAME}_LIB PUBLIC include)

target_link_libraries(${PROJECT_NAME}_LIB SDL3-shared)
target_link_libraries(${PROJECT_NAME}_LIB Core)

add_executable(
    ${PROJECT_NAME}_BIN
    "srcbin/main.c"
    "srcbin/Thing.c"
)

target_link_libraries(
    ${PROJECT_NAME}_BIN 
    ${PROJECT_NAME}_LIB
)

if(WIN32)
    set(lib_ext ".dll")
elseif(APPLE)
    set(lib_ext ".dylib")
else()
    set(lib_ext ".so")
endif()

foreach(tar SDL3-shared)
    add_custom_command(TARGET ${PROJECT_NAME}_LIB POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${tar}>
        ${PROJECT_BINARY_DIR}
    )
endforeach()