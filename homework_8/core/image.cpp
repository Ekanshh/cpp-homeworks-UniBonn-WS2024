#include "image.hpp"

#include <algorithm>

namespace igg {

Image::Image(const int& rows, const int& cols)
    : rows_(rows),
      cols_(cols),
      data_(static_cast<std::vector<Pixel>::size_type>(rows_ * cols_ * 3)){};

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
            int new_index = row * new_cols + col * 3;
            int old_index = (row * scale) * cols_ + (col * scale) * 3;
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
            int new_index = row * new_cols + col * 3;
            int old_index = (row / scale) * cols_ + (col / scale) * 3;
            new_data[new_index] = data_[old_index];
        }
    }

    rows_ = new_rows;
    cols_ = new_cols;
    data_ = new_data;

    for (int row = 0; row < new_rows; row++) {
        for (int col = 0; col < new_cols; col++) {
            int new_index = row * new_cols + col * 3;
            if (new_data[new_index].red == 0 && new_data[new_index].green == 0 &&
                new_data[new_index].blue == 0) {
                int nearest_index = new_index;
                while (new_data[nearest_index].red == 0 && new_data[nearest_index].green == 0 &&
                       new_data[nearest_index].blue == 0) {
                    nearest_index += 3;
                }
                new_data[new_index] = new_data[nearest_index];
            }
        }
    }
}
}  // namespace igg