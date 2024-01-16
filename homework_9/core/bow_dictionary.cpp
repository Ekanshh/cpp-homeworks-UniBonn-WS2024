#include "bow_dictionary.hpp"

#include <algorithm>

namespace ipb {

cv::Mat kMeans(const std::vector<cv::Mat> &descriptors, int k, int max_iter) {
    cv::Mat descriptors_mat;
    cv::Mat centers;
    cv::Mat labels;

    for (const auto &descriptor : descriptors) {
        descriptors_mat.push_back(descriptor);
    }

    cv::kmeans(descriptors_mat, k, labels,
               cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, max_iter, 1.0), 3,
               cv::KMEANS_RANDOM_CENTERS, centers);
    return centers;
}

BowDictionary &BowDictionary::GetInstance() {
    static BowDictionary instance;
    return instance;
}

void BowDictionary::build(int max_iterations,
                          std::size_t size,
                          const std::vector<cv::Mat> &descriptors) {
    auto vocabulary = kMeans(descriptors, static_cast<int>(size), max_iterations);
    set_vocabulary(vocabulary);
}

void BowDictionary::set_vocabulary(const cv::Mat &vocabulary) { vocabulary_ = vocabulary.clone(); }

std::size_t BowDictionary::size() const {
    return static_cast<std::size_t>(vocabulary_.empty() ? 0 : vocabulary_.rows);
}
bool BowDictionary::empty() const { return vocabulary_.empty(); }

}  // namespace ipb