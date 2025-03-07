cmake_minimum_required(VERSION 3.14)

# Set up vcpkg
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

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
