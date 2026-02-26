cmake_minimum_required(VERSION 3.10)

# Project name
project(Snake VERSION 1.0)

# C++ configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Indicate where the header files are found
include_directories(include)

# Gather the source files
file(GLOB_RECURSE PROJECT_SOURCE "src/*.cpp")

# Create the final executable
add_executable(Snake ${PROJECT_SOURCE})

# Link the libraries
target_link_libraries(Snake)