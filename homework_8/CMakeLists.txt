cmake_minimum_required(VERSION 3.16...3.28.1)

project(homework_8)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PNG REQUIRED)

# Include subdirectories
add_subdirectory(core)
add_subdirectory(interface)
add_subdirectory(tests)
