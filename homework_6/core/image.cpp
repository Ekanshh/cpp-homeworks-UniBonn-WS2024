#include "image.hpp"

#include <algorithm>

#include "io_tools.hpp"

namespace igg {

Image::Image() : rows_(0), cols_(0), data_(0) {}
Image::Image(const int& rows, const int& cols)
    : rows_(rows), cols_(cols), data_(static_cast<std::size_t>(rows * cols)) {}
Image::~Image() = default;

int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }
std::vector<uint8_t> Image::data() const { return data_; }

const uint8_t& Image::at(int row, int col) const { return data_[row * cols_ + col]; }
uint8_t& Image::at(int row, int col) { return data_[row * cols_ + col]; }

bool Image::FillFromPgm(const std::string& file_name) {
    io_tools::ImageData image_data = io_tools::ReadFromPgm(file_name);
    rows_ = image_data.rows;
    cols_ = image_data.cols;
    data_ = image_data.data;
    return true;
}

void Image::WriteToPgm(const std::string& file_name) {
    io_tools::ImageData image_data;
    image_data.rows = rows_;
    image_data.cols = cols_;
    image_data.max_val = *std::max_element(data_.begin(), data_.end());
    image_data.data = data_;
    io_tools::WriteToPgm(image_data, file_name);
}
}  // namespace igg