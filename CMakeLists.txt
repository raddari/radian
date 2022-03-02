cmake_minimum_required(VERSION 3.19)
project(radian LANGUAGES C VERSION 0.1.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(PreventInSourceBuilds)

add_library(radian INTERFACE)
add_library(radian::radian ALIAS radian)

target_sources(radian INTERFACE ${CMAKE_SOURCE_DIR}/include/radian/radian.h)
target_include_directories(radian INTERFACE ${CMAKE_SOURCE_DIR}/include)

option(RADIAN_BUILD_TESTS "Build radian testing suite using Unity" OFF)

if(RADIAN_BUILD_TESTS AND BUILD_TESTING)
  include(CTest)
  add_subdirectory(test)
endif()
