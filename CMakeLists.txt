cmake_minimum_required(VERSION 3.16)

project(SEICO VERSION 0.1 LANGUAGES CXX)

# IMPORTANT INFORMATION
# UIC = User Interface Compiler - uic is a QT compiler that compiles QT .ui files which are in XML format
# At build time, CMake scans each header and source file from the target's sources for include statements of the form
# #include "ui_<ui_base>.h"
# Once such an include statement is found in a file, CMake searches for the uic input file <ui_base>.ui in the following paths:
# 1) in the vicinity of the file
# 2) in the AUTOUIC_SEARCH_PATHS of the target.
# If the <ui_base>.ui file was found, uic is called on it to generate ui_<ui_base>.h in one of the following directories:
# 1) <AUTOGEN_BUILD_DIR>/include for single configuration generators
# 2) <AUTOGEN_BUILD_DIR>/include_<CONFIG> for multi configuration generators.
# The include directory is automatically added to the target's INCLUDE_DIRECTORIES.

# # AUTOUIC is a boolean specifying whether CMake will handle the Qt uic code generator automatically,
# i.e. without having to use commands like QT4_WRAP_UI(), qt5_wrap_ui(), etc. Currently, Qt versions 4 to 6 are supported.
# This property is initialized by the value of the CMAKE_AUTOUIC variable if it is set when a target is created.
set(CMAKE_AUTOUIC ON)
# CMAKE_AUTOUIC_SEARCH_PATHS variable is used to initialize AUTOUIC_SEARCH_PATHS property on all the targets.
# UTOUIC_SEARCH_PATHS is a search path list used by CMAKE_AUTOUIC to find included .ui files.
set(CMAKE_AUTOUIC_SEARCH_PATHS include)

# MOC = Meta-Object Compiler - a QT program that handles Qt's C++ extensions.
# The moc tool reads a C++ header file. If it finds one or more class declarations that contain the Q_OBJECT macro,
# it produces a C++ source file containing the meta-object code for those classes.

# AUTOMOC is a boolean specifying whether CMake will handle the Qt moc preprocessor automatically,
# i.e. without having to use commands like QT4_WRAP_CPP(), qt5_wrap_cpp(), etc. Currently, Qt versions 4 to 6 are supported.
# This property is initialized by the value of the CMAKE_AUTOMOC variable if it is set when a target is created.
set(CMAKE_AUTOMOC ON)

# RCC = Resource Compiler - a tool used to embed resources into a Qt application during the build process.
# rcc works by generating a C++ source file containing data specified in a Qt resource (.qrc) file.
set(CMAKE_AUTORCC ON)

# Set the minimum required C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Search for the Widgets module in the QT library (QT5 or QT6)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Add all project .cpp, .h, and .ui files
set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/Logging.cpp
        src/trace.cpp
        src/messagedatamodel.cpp
        include/mainwindow.h
        include/logging.h
        include/trace.h
        include/message.h
        include/messagedatamodel.h
        include/SEICO.ui
)

# Create and set a variable containing include directories for header files
set(INCLUDE_DIRECTORIES
    include
)

# Build the target from sources (QT6)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SEICO
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Build the target from sources (QT5)
else()
    add_executable(SEICO
        ${PROJECT_SOURCES}
    )
endif()

# Link the Widgets module from the QT library to the built target
target_link_libraries(SEICO PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Specify include directories to use when compiling the target.The target must have been created first.
target_include_directories(SEICO PRIVATE ${INCLUDE_DIRECTORIES})

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SEICO)
endif()

set_target_properties(SEICO PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)

install(TARGETS SEICO
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SEICO)
endif()
