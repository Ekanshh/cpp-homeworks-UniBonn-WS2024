cmake_minimum_required(VERSION 3.1)

project(homework_3)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include subdirectories
add_subdirectory(api)
add_subdirectory(interface)