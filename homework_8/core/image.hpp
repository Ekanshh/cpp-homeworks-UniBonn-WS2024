#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "io_strategies.hpp"

namespace igg {

class Image {
public:
    Image() = default;
    Image(const int& rows, const int& cols);

    struct Pixel {
        int red;
        int green;
        int blue;
    };

    [[nodiscard]] int rows() const;
    [[nodiscard]] int cols() const;
    [[nodiscard]] std::vector<Pixel> data() const;

    [[nodiscard]] const Pixel& at(int row, int col) const;
    Pixel& at(int row, int col);

    void DownScale(int scale);
    void UpScale(int scale);

    void SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr) {
        strategy_ptr_ = std::move(strategy_ptr);
    }

    bool ReadFromDisk(const std::string& file_name);
    void WriteToDisk(const std::string& file_name, const ImageData& image);

private:
    int rows_ = 0;
    int cols_ = 0;
    std::vector<Pixel> data_;
    std::shared_ptr<IoStrategy> strategy_ptr_ = nullptr;
};

}  // namespace igg