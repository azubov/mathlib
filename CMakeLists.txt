cmake_minimum_required(VERSION 3.28.3)
project(Mathlib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Библиотека без указания STATIC/SHARED → тип определяется через BUILD_SHARED_LIBS
add_library(mathlib src/math_operations.cpp)

target_include_directories(mathlib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(CTest)
if (BUILD_TESTING)
    add_subdirectory(tests)
endif()