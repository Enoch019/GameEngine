cmake_minimum_required(VERSION 3.10)
project(PepGE VERSION 0.0.0)

find_package(OpenGL REQUIRED)
link_libraries(OpenGL::OpenGL)

add_subdirectory(ext/SDL)
add_subdirectory(ext/Core)

if(_WIN32)

add_subdirectory(ext/EGL/EGL)
link_libraries(egl)

endif()

add_library(
    "${PROJECT_NAME}_LIB"
    "src/PepGE.c" "include/PepGE.h"
)

target_include_directories(${PROJECT_NAME}_LIB PUBLIC include)

target_link_libraries(${PROJECT_NAME}_LIB SDL3-shared)
target_link_libraries(${PROJECT_NAME}_LIB Core)

add_executable(
    ${PROJECT_NAME}_BIN
    "srcbin/main.c"
)

target_link_libraries(
    ${PROJECT_NAME}_BIN 
    ${PROJECT_NAME}_LIB
)