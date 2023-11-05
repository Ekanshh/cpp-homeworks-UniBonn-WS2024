cmake_minimum_required(VERSION 3.10)
project(homework_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(./include)  

add_library(ipb_arithmetic src/subtract.cpp src/sum.cpp)
add_executable(test_ipb_arithmetic src/main.cpp)
target_link_libraries(test_ipb_arithmetic ipb_arithmetic)


# Set the installation paths
set(INSTALL_INCLUDE_DIR "include")
set(INSTALL_LIB_DIR "lib")

# Install headers
install(DIRECTORY include/ DESTINATION ${INSTALL_INCLUDE_DIR})
# Install libraries
install(TARGETS ipb_arithmetic DESTINATION ${INSTALL_LIB_DIR})


# Copy files to results
set(BUILD_DIR ${CMAKE_BINARY_DIR})
set(RESULTS_DIR ${BUILD_DIR}/../results)
# Copy the executable to results/bin
add_custom_command(
    TARGET test_ipb_arithmetic
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        ${RESULTS_DIR}/bin
    COMMAND ${CMAKE_COMMAND} -E copy
        ${BUILD_DIR}/test_ipb_arithmetic
        ${RESULTS_DIR}/bin/
)
# Copy the library to results/lib
add_custom_command(
    TARGET ipb_arithmetic
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        ${RESULTS_DIR}/lib
    COMMAND ${CMAKE_COMMAND} -E copy
        ${BUILD_DIR}/libipb_arithmetic.a
        ${RESULTS_DIR}/lib/
)
