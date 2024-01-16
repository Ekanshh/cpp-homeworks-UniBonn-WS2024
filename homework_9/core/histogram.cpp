

#include "histogram.hpp"

#include <fstream>

namespace ipb {

Histogram::Histogram(const cv::Mat& descriptors, const BowDictionary& dictionary) {
    std::cout << "Inside Histogram" << std::endl;
    auto vocabulary = dictionary.vocabulary();

    cv::Ptr<cv::DescriptorMatcher> matcher =
            cv::DescriptorMatcher::create(cv::DescriptorMatcher::FLANNBASED);

    std::cout << "Before data Histogram" << std::endl;
    std::vector<cv::DMatch> matches;
    matcher->match(descriptors, vocabulary, matches);
    if (!matches.empty()) {
        std::vector<int> histogram(vocabulary.rows, 0);
        for (const auto& match : matches) {
            histogram[match.trainIdx]++;
        }
        std::copy(histogram.begin(), histogram.end(), std::back_inserter(data_));
    }
}

std::ostream& operator<<(std::ostream& os, const Histogram& histogram) {
    for (const auto& bin : histogram.data_) {
        os << bin << ", ";
    }
    return os;
}

void Histogram::WriteToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    for (int i : data_) {
        file << i << ',';
    }
}

Histogram Histogram::ReadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return {};
    }

    std::string line;
    std::vector<int> data;
    while (!file.eof()) {
        std::getline(file, line);
        std::istringstream iss(line);
        std::string token;
        while (std::getline(iss, token, ',')) {
            data.push_back(std::stoi(token));
        }
    }
    return Histogram(data);
}

const int& Histogram::operator[](std::size_t index) const { return data_[index]; }
int& Histogram::operator[](std::size_t index) { return data_[index]; }

std::size_t Histogram::size() const { return data_.size(); }
bool Histogram::empty() const { return data_.empty(); }

std::vector<int>::iterator Histogram::begin() { return data_.begin(); }
std::vector<int>::iterator Histogram::end() { return data_.end(); }
const std::vector<int>::const_iterator Histogram::begin() const { return data_.begin(); }
const std::vector<int>::const_iterator Histogram::end() const { return data_.end(); }
const std::vector<int>::const_iterator Histogram::cbegin() const { return data_.cbegin(); }
const std::vector<int>::const_iterator Histogram::cend() const { return data_.cend(); }

std::vector<int> Histogram::data() const { return data_; }
}  // namespace ipb
