cmake_minimum_required(VERSION 3.14)

# Detect Apple Silicon
if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    set(CMAKE_OSX_ARCHITECTURES "arm64" CACHE STRING "")
    set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0" CACHE STRING "")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -arch arm64")
endif()

# Set up vcpkg with M1 compatible path
if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    set(CMAKE_TOOLCHAIN_FILE "/opt/homebrew/Cellar/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
else()
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(ClassDefinitions)
# Add source files
file(GLOB SOURCES *.cc *.h)

# Create executable
add_executable(class_definitions ${SOURCES})

find_package(GTest CONFIG REQUIRED)

# Link GTest
target_link_libraries(class_definitions PRIVATE GTest::gtest GTest::gtest_main)

# Set C++ standard
set_property(TARGET class_definitions PROPERTY CXX_STANDARD 20)
