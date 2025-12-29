include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

if(NOT TARGET mathlib)
    message(FATAL_ERROR "Target mathlib must be defined before including InstallMathlib.cmake")
endif()

# install headers
install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# install target and export
install(TARGETS mathlib
        EXPORT mathlibTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT mathlibTargets
        FILE mathlibTargets.cmake
        NAMESPACE mathlib::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mathlib)

# generate config files
set(CONFIG_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/mathlib)
configure_package_config_file(
        "${CMAKE_CURRENT_LIST_DIR}/MathlibConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/mathlibConfig.cmake"
        INSTALL_DESTINATION ${CONFIG_INSTALL_DIR})

write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/mathlibConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/mathlibConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/mathlibConfigVersion.cmake"
        DESTINATION ${CONFIG_INSTALL_DIR})
