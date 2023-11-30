find_package(Catch2 REQUIRED)
include(Catch)

set(TEST_BINARY ${PROJECT_NAME}_test)
# add_executable(${TEST_BINARY} test_named_vector.cpp test_ipb_algorithm.cpp)
add_executable(${TEST_BINARY} test_named_vector.cpp)
target_link_libraries(${TEST_BINARY} homework_4 Catch2::Catch2WithMain)
catch_discover_tests(${TEST_BINARY} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
