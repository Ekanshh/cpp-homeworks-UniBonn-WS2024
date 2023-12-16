// @file       io_tools.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Igor Bogoslavskyi , all rights reserved
#include "io_tools.hpp"

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

namespace igg::io_tools {

ImageData ReadFromPgm(const std::string& file_name) {
    std::ifstream pgm_file(file_name, std::ios_base::in);
    if (!pgm_file) {
        return {0, 0, 0, {}};
    }

    // Read integers, if we read chars, we get 1 digit instead of the whole
    // number
    std::string type;
    int rows = 0;
    int cols = 0;
    int max_val = 0;
    std::vector<uint8_t> data;
    pgm_file >> type >> rows >> cols >> max_val;

    data.resize(static_cast<int>(rows * cols));
    int byte = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            pgm_file >> byte;
            data[row * cols + col] = byte;
        }
    }
    return {rows, cols, static_cast<uint8_t>(max_val), data};
}

bool WriteToPgm(const ImageData& image_data, const std::string& file_name) {
    std::ofstream pgm_file(file_name);
    if (!pgm_file) {
        return false;
    }
    pgm_file << "P2" << std::endl
             << image_data.rows << " " << image_data.cols << std::endl
             << image_data.max_val << std::endl;
    for (int row = 0; row < image_data.rows; ++row) {
        for (int col = 0; col < image_data.cols; ++col) {
            pgm_file << image_data.data[row * image_data.cols + col] << " ";
        }
        pgm_file << std::endl;
    }
    return true;
}

}  // namespace igg::io_tools
