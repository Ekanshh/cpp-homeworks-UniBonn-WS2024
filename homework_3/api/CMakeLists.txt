add_library(homework_3 STATIC

    html_writer.cpp
    image_browser.cpp
)

target_link_libraries(homework_3 PUBLIC fmt)