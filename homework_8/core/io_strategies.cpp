#include "io_strategies.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace igg {

ImageData PngIoStrategy::ReadFromDisk(const std::string& file_name) const {
    png::image<png::rgb_pixel> image(file_name);
    png_uint_32 rows_ = image.get_height();
    png_uint_32 cols_ = image.get_width();
    std::vector<png::rgb_pixel> data_(
            static_cast<std::vector<png::rgb_pixel>::size_type>(rows_ * cols_));
    for (auto row = 0; row < rows_; row++) {
        for (auto col = 0; col < cols_; col++) {
            data_[row * cols_ + col].red = image[row][col].red;
            data_[row * cols_ + col].green = image[row][col].green;
            data_[row * cols_ + col].blue = image[row][col].blue;
        }
    }

    return ImageData{rows_, cols_, data_};
}
void PngIoStrategy::WriteToDisk(const std::string& file_name, const ImageData& image) const {
    {
        png::image<png::rgb_pixel> png_image(image.cols, image.rows);
        for (auto row = 0; row < image.rows; row++) {
            for (auto col = 0; col < image.cols; col++) {
                png_image[row][col].red = image.data[row * image.cols + col].red;
                png_image[row][col].green = image.data[row * image.cols + col].green;
                png_image[row][col].blue = image.data[row * image.cols + col].blue;
            }
        }
        png_image.write(file_name);
    }
}

// PpmIoStrategy
ImageData PpmIoStrategy::ReadFromDisk(const std::string& file_name) const {
    std::ifstream ppm_file(file_name, std::ios::in);
    if (!ppm_file.is_open()) {
        return ImageData{0, 0, {}};
    }

    png::uint_32 rows = 0;
    png::uint_32 cols = 0;
    png::uint_32 max = 0;
    std::vector<png::rgb_pixel> data(
            static_cast<std::vector<png::rgb_pixel>::size_type>(rows * cols));

    std::string line;
    std::getline(ppm_file, line);
    if (line != "P3") {
        return ImageData{0, 0, {}};
    }

    std::getline(ppm_file, line);
    std::cout << "line: " << line << std::endl;
    std::stringstream ss(line);
    ss >> cols >> rows;

    std::cout << "cols: " << cols << " rows: " << rows << std::endl;
    std::getline(ppm_file, line);
    std::stringstream ss_max(line);
    ss_max >> max;

    while (!ppm_file.eof()) {
        std::getline(ppm_file, line);
        std::stringstream ss_data(line);
        int red = 0;
        int green = 0;
        int blue = 0;
        while (!ss_data.eof()) {
            ss_data >> red >> green >> blue;
            data.emplace_back(red, green, blue);
        }
    }

    return ImageData{rows, cols, data};
}

void PpmIoStrategy::WriteToDisk(const std::string& file_name, const ImageData& image) const {
    // Open file
    std::fstream file(file_name, std::ios::out);
    if (file.is_open()) {
        // Write header
        file << "P3" << std::endl;
        file << image.cols << " " << image.rows << std::endl;
        file << "255" << std::endl;

        // Write data
        for (auto i = 0; i < image.rows * image.cols; i++) {
            file << static_cast<int>(image.data[i].red) << " "
                 << static_cast<int>(image.data[i].green) << " "
                 << static_cast<int>(image.data[i].blue) << std::endl;
        }
        // Close file
        file.close();
    }
}
}  // namespace igg