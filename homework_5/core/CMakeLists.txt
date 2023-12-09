add_library(mat_serialization STATIC
    serialize.cpp
)

add_library(convert_dataset STATIC
    convert_dataset.cpp
    serialize.cpp
)