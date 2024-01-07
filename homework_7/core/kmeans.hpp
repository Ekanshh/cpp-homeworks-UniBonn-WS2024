#pragma once

#include <opencv2/core.hpp>
#include <vector>

namespace ipb {

cv::Mat kMeans(const std::vector<cv::Mat> &descriptors, int k, int max_iter);

class BowDictionary {
protected:
    BowDictionary() = default;

public:
    static BowDictionary &GetInstance();

    BowDictionary(const BowDictionary &) = delete;
    BowDictionary(BowDictionary &&) = delete;
    BowDictionary &operator=(const BowDictionary &) = delete;
    BowDictionary &operator=(BowDictionary &&) = delete;
    ~BowDictionary() = default;

    void set_params(int max_iterations, std::size_t size, const std::vector<cv::Mat> &descriptors);

    int max_iterations() const;
    std::size_t size() const;
    std::vector<cv::Mat> descriptors() const;
    cv::Mat codebook() const;

    void set_max_iterations(int new_max_iterations);
    void set_size(int size);
    void set_descriptors(const std::vector<cv::Mat> &descriptors);

    int total_features() const;
    bool empty() const;

private:
    void compute_codebook_();

    int max_iterations_{};
    std::size_t dict_size_{};  // number of visual words
    std::vector<cv::Mat> descriptors_{};
    cv::Mat codebook_{};
};
}  // namespace ipb