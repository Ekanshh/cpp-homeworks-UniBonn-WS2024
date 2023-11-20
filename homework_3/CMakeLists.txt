# Reference: https://github.com/sun1211/cmake_with_add_subdirectory
cmake_minimum_required(VERSION 3.1)

project(homework_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the path to the ClangFormat.cmake script
set(CLANG_FORMAT_SCRIPT_PATH "${CMAKE_SOURCE_DIR}/cmake/ClangFormat.cmake")
set(STATIC_ANALYZER_SCRIPT_PATH "${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake")

# Include target directories for header file
include_directories(homework_3/)

add_library(homework_3 api/html_writer.cpp api/image_browser.cpp)