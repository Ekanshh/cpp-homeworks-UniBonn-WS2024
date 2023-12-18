#pragma once

#include <iostream>
#include <vector>

namespace igg {
class Image {
public:
    Image();
    Image(const int& rows, const int& cols);
    ~Image();

    [[nodiscard]] int rows() const;
    [[nodiscard]] int cols() const;
    [[nodiscard]] std::vector<uint8_t> data() const;

    [[nodiscard]] const uint8_t& at(int row, int col) const;
    uint8_t& at(int row, int col);

    bool FillFromPgm(const std::string& file_name);
    void WriteToPgm(const std::string& file_name);

    std::vector<float> ComputeHistogram(int bins) const;

private:
    int rows_;
    int cols_;
    std::vector<uint8_t> data_;
};
}  // namespace igg