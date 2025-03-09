cmake_minimum_required(VERSION 3.14)

# Detect Apple Silicon
if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    set(CMAKE_OSX_ARCHITECTURES "arm64" CACHE STRING "")
    set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0" CACHE STRING "")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -arch arm64")
endif()

project(VTable)

# Add source files
file(GLOB SOURCES *.cc *.h)

# Create executable
add_executable(vtable ${SOURCES})

set_property(TARGET vtable PROPERTY CXX_STANDARD 20)
