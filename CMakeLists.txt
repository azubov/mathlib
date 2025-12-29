cmake_minimum_required(VERSION 3.28.3)
project(Mathlib VERSION 1.0.0
        DESCRIPTION "Small C++ math library"
        HOMEPAGE_URL "https://github.com/azubov/mathlib"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Библиотека без указания STATIC/SHARED → тип определяется через BUILD_SHARED_LIBS
add_library(mathlib src/math_operations.cpp)

# ALIAS для удобства: делает mathlib::mathlib доступным при add_subdirectory (CPM)
if (NOT TARGET mathlib::mathlib)
    add_library(mathlib::mathlib ALIAS mathlib)
endif()

# Версионирование библиотеки
set_target_properties(mathlib PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})

target_include_directories(mathlib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

include(CTest)
if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()

# подключаем файл с установкой и генерацией config-файлов
include(cmake/InstallMathlib.cmake)