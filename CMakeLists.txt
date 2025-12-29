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

# Версионирование библиотеки
set_target_properties(mathlib PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1)

target_include_directories(mathlib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

# --- Установка библиотеки и заголовков ---
install(TARGETS mathlib
        EXPORT mathlibTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)

# --- Экспорт таргетов в пакет ---
install(EXPORT mathlibTargets
        FILE mathlibConfig.cmake
        NAMESPACE mathlib::
        DESTINATION lib/cmake/mathlib)

# --- Файл версии пакета ---
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/mathlibConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/mathlibConfigVersion.cmake"
        DESTINATION lib/cmake/mathlib)

include(CTest)
if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()