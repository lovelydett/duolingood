cmake_minimum_required(VERSION 3.14)

project(VTable)

# Add source files
file(GLOB SOURCES *.cc *.h)

# Create executable
add_executable(vtable ${SOURCES})

set_property(TARGET vtable PROPERTY CXX_STANDARD 20)
