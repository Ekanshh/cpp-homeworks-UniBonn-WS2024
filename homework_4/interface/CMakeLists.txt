add_library(homework_4 INTERFACE)

target_include_directories(homework_4 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../core
)

target_link_libraries(homework_4 INTERFACE ipb)