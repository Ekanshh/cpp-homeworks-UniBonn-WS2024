#pragma once

#include <png++/png.hpp>

namespace igg {

/// Dummy structure to store relevant image data.
struct ImageData {
    png::uint_32 rows{};
    png::uint_32 cols{};
    std::vector<png::rgb_pixel> data{};
};

class IoStrategy {
public:
    virtual ImageData ReadFromDisk(const std::string& file_name) const = 0;
    virtual void WriteToDisk(const std::string& file_name, const ImageData& image) const = 0;
};

class PngIoStrategy : public IoStrategy {
public:
    ImageData ReadFromDisk(const std::string& file_name) const override;
    void WriteToDisk(const std::string& file_name, const ImageData& image) const override;
};

class PpmIoStrategy : public IoStrategy {
public:
    ImageData ReadFromDisk(const std::string& file_name) const override;
    void WriteToDisk(const std::string& file_name, const ImageData& image) const override;
};
}  // namespace igg