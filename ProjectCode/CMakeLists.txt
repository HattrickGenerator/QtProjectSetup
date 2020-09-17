cmake_minimum_required(VERSION 3.2.2)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Store version into variable
set(buildDir build)
set(ProjectName QtProject)
set(ExectuableCode ExecutableCode)
set(libProject MainProjectLibrary)
set(testLib TestLibrary)


project (${ProjectName})

#Add packages and append them to list for includes
find_package(Qt5 COMPONENTS Core Widgets Qml Quick QuickWidgets 3DCore 3DExtras REQUIRED)

list( APPEND QT_LIBRARIES
Qt5::Core 
Qt5::Widgets
Qt5::Qml
Qt5::Quick
Qt5::QuickWidgets
Qt5::3DCore
Qt5::3DExtras
)


#####

#Packages
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../${buildDir})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../${buildDir})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../${buildDir})

#Add Subdirectories for library, executable and test library
add_subdirectory(${libProject})
add_subdirectory(${ExectuableCode})





############
#Set up Google test installation
#Thanks to: https://chromium.googlesource.com/external/github.com/google/googletest/+/HEAD/googletest/README.md

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in ${testLib}/googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${testLib}/googletest-download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${testLib}/googletest-download"
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/${testLib}/googletest-src"
                 "${CMAKE_BINARY_DIR}/${testLib}/googletest-build"
)

add_subdirectory(${testLib})
############





##Set output Directory to build directory


