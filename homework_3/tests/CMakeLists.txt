find_package(GTest REQUIRED)

set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(${TEST_BINARY} test_image_browser.cpp test_html_writer.cpp)
target_link_libraries(${TEST_BINARY} homework_3 GTest::Main)
gtest_discover_tests(${TEST_BINARY})
