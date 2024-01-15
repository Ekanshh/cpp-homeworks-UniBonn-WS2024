#pragma once

#include <iostream>
#include <vector>

namespace igg {

class Image {
public:
    Image() = default;
    Image(const int& rows, const int& cols);

    struct Pixel {
        int red = 0;
        int green = 0;
        int blue = 0;
    };

    [[nodiscard]] int rows() const;
    [[nodiscard]] int cols() const;
    [[nodiscard]] std::vector<Pixel> data() const;

    [[nodiscard]] const Pixel& at(int row, int col) const;
    Pixel& at(int row, int col);

    void DownScale(int scale);
    void UpScale(int scale);

private:
    int rows_ = 0;
    int cols_ = 0;
    std::vector<Pixel> data_;
};

}  // namespace igg