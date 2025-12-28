cmake_minimum_required(VERSION 3.28.3)
project(Mathlib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;--warnings-as-errors=*")

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
add_library(mathlib src/math_operations.cpp)
target_include_directories(mathlib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(CTest)
if (BUILD_TESTING)
    add_subdirectory(tests)
endif()