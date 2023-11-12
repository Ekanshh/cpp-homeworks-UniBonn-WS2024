# Reference: https://github.com/sun1211/cmake_with_add_subdirectory

cmake_minimum_required(VERSION 3.1)
project(homework_2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include(cmake/ClangFormat.cmake)
# include(cmake/StaticAnalyzers.cmake)

# defines targets and sources
add_subdirectory(task_1)

# Add clang-format target

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

