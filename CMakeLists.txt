cmake_minimum_required(VERSION 3.20)
project(radian LANGUAGES C VERSION 0.1.0)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(PreventInSourceBuilds)

add_library(radian INTERFACE)
add_library(radian::radian ALIAS radian)

target_sources(radian INTERFACE
    ${PROJECT_SOURCE_DIR}/include/radian/radian.h
    ${PROJECT_SOURCE_DIR}/include/radian/radian-internal.h
)
target_include_directories(radian INTERFACE ${PROJECT_SOURCE_DIR}/include)

option(RADIAN_BUILD_TESTS "Build radian testing suite using Unity" OFF)

if(${CMAKE_C_BYTE_ORDER} STREQUAL BIG_ENDIAN)
  target_compile_definitions(radian INTERFACE RADIAN_HOST_BE)
else()
  target_compile_definitions(radian INTERFACE RADIAN_HOST_LE)
endif()

if(RADIAN_BUILD_TESTS AND BUILD_TESTING)
  include(CTest)
  add_subdirectory(test)
endif()
