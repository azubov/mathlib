cmake_minimum_required(VERSION 3.15)
project(mathlib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(MATHLIB_BUILD_TESTS "Build mathlib tests" OFF)

add_library(mathlib src/math_operations.cpp)
target_include_directories(mathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(MATHLIB_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
