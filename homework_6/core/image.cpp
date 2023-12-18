#include "image.hpp"

#include <algorithm>

#include "io_tools.hpp"

namespace igg {

Image::Image() = default;
Image::Image(const int& rows, const int& cols)
    : rows_(rows), cols_(cols), data_(static_cast<std::size_t>(rows * cols)){};

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

std::vector<float> Image::ComputeHistogram(int bins) const {
    std::vector<float> histogram(bins, 0.0F);
    int bin_width = 255 / bins;

    for (const auto& pixel_val : data_) {
        int bin_index = static_cast<int>(pixel_val / bin_width);
        bin_index = std::max(0, std::min(bin_index, bins - 1));
        histogram[bin_index] += 1.0F;
    }

    std::vector<float> normalized_histogram(bins, 0.0F);
    for (std::size_t i = 0; i < histogram.size(); i++) {
        normalized_histogram[i] = histogram[i] / static_cast<float>(data_.size());
    }

    return normalized_histogram;
}

void Image::DownScale(int scale) {
    int new_rows = rows_ / scale;
    int new_cols = cols_ / scale;
    std::vector<uint8_t> new_data(static_cast<std::size_t>(new_rows * new_cols));

    for (int row = 0; row < new_rows; row++) {
        for (int col = 0; col < new_cols; col++) {
            int new_index = row * new_cols + col;
            int old_index = (row * scale) * cols_ + (col * scale);
            new_data[new_index] = data_[old_index];
        }
    }

    rows_ = new_rows;
    cols_ = new_cols;
    data_ = new_data;
}
void Image::UpScale(int scale) {
    int new_rows = rows_ * scale;
    int new_cols = cols_ * scale;
    std::vector<uint8_t> new_data(static_cast<std::size_t>(new_rows * new_cols));

    for (int row = 0; row < new_rows; row++) {
        for (int col = 0; col < new_cols; col++) {
            int new_index = row * new_cols + col;
            int old_index = (row / scale) * cols_ + (col / scale);
            new_data[new_index] = data_[old_index];
        }
    }

    rows_ = new_rows;
    cols_ = new_cols;
    data_ = new_data;
}
}  // namespace igg