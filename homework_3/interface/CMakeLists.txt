add_library(homework_3 INTERFACE)

target_include_directories(homework_3 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../api
)

target_link_libraries(homework_3 INTERFACE html_api)