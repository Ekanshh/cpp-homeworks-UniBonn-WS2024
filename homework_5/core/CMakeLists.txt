add_library(mat_serialization STATIC
    serialize.cpp
)
target_link_libraries(mat_serialization 
    PRIVATE ${OpenCV_LIBS})

add_library(convert_dataset STATIC
    convert_dataset.cpp
    serialize.cpp
)
target_link_libraries(convert_dataset 
    PRIVATE ${OpenCV_LIBS})