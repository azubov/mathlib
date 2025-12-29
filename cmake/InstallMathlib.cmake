include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

if(NOT TARGET mathlib)
    message(FATAL_ERROR "Target mathlib must be defined before including InstallMathlib.cmake")
endif()

# Установить заголовки (копируем папку include)
install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Установить таргет и экспортировать его с namespace mathlib::
install(TARGETS mathlib
        EXPORT MathlibTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT MathlibTargets
        FILE MathlibTargets.cmake
        NAMESPACE mathlib::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Mathlib)

# Сгенерировать и установить MathlibConfig.cmake и MathlibConfigVersion.cmake
set(CONFIG_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/Mathlib)
configure_package_config_file(
        "${CMAKE_CURRENT_LIST_DIR}/MathlibConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/MathlibConfig.cmake"
        INSTALL_DESTINATION ${CONFIG_INSTALL_DIR})

write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/MathlibConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/MathlibConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/MathlibConfigVersion.cmake"
        DESTINATION ${CONFIG_INSTALL_DIR})
