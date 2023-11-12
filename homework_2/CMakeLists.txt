# Reference: https://github.com/sun1211/cmake_with_add_subdirectory

cmake_minimum_required(VERSION 3.1)
project(homework_2)
set(CMAKE_CXX_STANDARD 17)

option(ENABLE_CLANG_TIDY    "Enable to add clang tidy."             ON)
option(ENABLE_CPPCHECK      "Enable to add cppcheck."               ON)
option(ENABLE_CLANG_FORMAT  "Enable to add clang format."           ON)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# defines targets and sources
add_subdirectory(task_1)

