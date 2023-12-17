add_library(libio_tools STATIC
    io_tools.cpp
)

add_library(libimage STATIC
    image.cpp
)

target_link_libraries(libimage 
    PUBLIC libio_tools)