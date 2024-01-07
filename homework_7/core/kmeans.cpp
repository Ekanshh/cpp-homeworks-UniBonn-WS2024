#include "kmeans.hpp"

#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>

namespace ipb {

// kMeans function implementation
cv::Mat kMeans(const std::vector<cv::Mat> &descriptors, int k, int max_iter) {
    cv::Mat descriptors_mat;
    cv::Mat centers;
    cv::Mat labels;

    for (const auto &desc : descriptors) {
        descriptors_mat.push_back(desc);
    }

    cv::kmeans(descriptors_mat, k, labels,
               cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, max_iter, 1.0), 3,
               cv::KMEANS_RANDOM_CENTERS, centers);
    return centers;
}

// BowDictionary class implementation
BowDictionary &BowDictionary::GetInstance() {
    static BowDictionary instance;
    return instance;
}
void BowDictionary::set_params(int max_iterations,
                               std::size_t size,
                               const std::vector<cv::Mat> &descriptors) {
    max_iterations_ = max_iterations;
    dict_size_ = size;
    descriptors_ = descriptors;
    compute_codebook_();
}
int BowDictionary::max_iterations() const { return max_iterations_; }
std::size_t BowDictionary::size() const { return dict_size_; }
std::vector<cv::Mat> BowDictionary::descriptors() const { return descriptors_; }
cv::Mat BowDictionary::codebook() const { return codebook_; }
void BowDictionary::set_max_iterations(int new_max_iterations) {
    max_iterations_ = new_max_iterations;
    compute_codebook_();
}
void BowDictionary::set_size(int size) {
    dict_size_ = size;
    compute_codebook_();
}
void BowDictionary::set_descriptors(const std::vector<cv::Mat> &descriptors) {
    descriptors_ = descriptors;
    compute_codebook_();
}
int BowDictionary::total_features() const {
    return std::accumulate(descriptors_.begin(), descriptors_.end(), 0,
                           [](int sum, const auto &desc) { return sum + desc.rows; });
}
bool BowDictionary::empty() const { return codebook_.empty(); }
void BowDictionary::compute_codebook_() {
    codebook_ = kMeans(descriptors_, static_cast<int>(dict_size_), max_iterations_);
}
}  // namespace ipb