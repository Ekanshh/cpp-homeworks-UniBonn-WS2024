#include "image.hpp"

#include <algorithm>

namespace igg {

Image::Image(const int& rows, const int& cols)
    : rows_(rows),
      cols_(cols),
      data_(static_cast<std::vector<Pixel>::size_type>(rows_ * cols_ * 3)) {}

int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }

std::vector<Image::Pixel> Image::data() const { return data_; }

const Image::Pixel& Image::at(int row, int col) const { return data_[row * cols_ + col]; }

Image::Pixel& Image::at(int row, int col) { return data_[row * cols_ + col]; }

void Image::DownScale(int scale) {
    int new_rows = rows_ / scale;
    int new_cols = cols_ / scale;
    std::vector<Pixel> new_data(static_cast<std::size_t>(new_rows * new_cols * 3));

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
    std::vector<Pixel> new_data(static_cast<std::size_t>(new_rows * new_cols * 3));

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

bool Image::ReadFromDisk(const std::string& file_name) {
    if (strategy_ptr_ == nullptr) {
        std::cerr << "Error: IoStrategy not set" << std::endl;
        std::quick_exit(1);
    }
    ImageData image = strategy_ptr_->ReadFromDisk(file_name);
    rows_ = static_cast<int>(image.rows);
    cols_ = static_cast<int>(image.cols);
    int data_size_ = rows_ * cols_ * 3;
    data_.resize(data_size_);

    for (int row = 0; row < rows_; row++) {
        for (int col = 0; col < cols_; col++) {
            data_[row * cols_ + col].red = image.data[row * cols_ + col].red;
            data_[row * cols_ + col].green = image.data[row * cols_ + col].green;
            data_[row * cols_ + col].blue = image.data[row * cols_ + col].blue;
        }
    }
    return true;
}

void Image::WriteToDisk(const std::string& file_name, const ImageData& image) {
    if (strategy_ptr_ == nullptr) {
        std::cerr << "Error: IoStrategy not set" << std::endl;
        std::quick_exit(1);
    }
    return strategy_ptr_->WriteToDisk(file_name, image);
}

}  // namespace igg