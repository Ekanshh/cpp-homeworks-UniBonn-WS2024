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
    IoStrategy() = default;
    IoStrategy(const IoStrategy&) = default;
    IoStrategy& operator=(const IoStrategy&) = default;
    IoStrategy(IoStrategy&&) = default;
    IoStrategy& operator=(IoStrategy&&) = default;
    virtual ~IoStrategy() = default;

    virtual ImageData ReadFromDisk(const std::string& file_name) const = 0;
    virtual void WriteToDisk(const std::string& file_name, const ImageData& image) const = 0;
};

class PngIoStrategy : public IoStrategy {
public:
    PngIoStrategy() = default;
    PngIoStrategy(const PngIoStrategy&) = default;
    PngIoStrategy& operator=(const PngIoStrategy&) = default;
    PngIoStrategy(PngIoStrategy&&) = default;
    PngIoStrategy& operator=(PngIoStrategy&&) = default;
    ~PngIoStrategy() override = default;

    ImageData ReadFromDisk(const std::string& file_name) const override;
    void WriteToDisk(const std::string& file_name, const ImageData& image) const override;
};

class PpmIoStrategy : public IoStrategy {
public:
    PpmIoStrategy() = default;
    ~PpmIoStrategy() override = default;
    PpmIoStrategy(const PpmIoStrategy&) = default;
    PpmIoStrategy& operator=(const PpmIoStrategy&) = default;
    PpmIoStrategy(PpmIoStrategy&&) = default;
    PpmIoStrategy& operator=(PpmIoStrategy&&) = default;

    ImageData ReadFromDisk(const std::string& file_name) const override;
    void WriteToDisk(const std::string& file_name, const ImageData& image) const override;
};
}  // namespace igg