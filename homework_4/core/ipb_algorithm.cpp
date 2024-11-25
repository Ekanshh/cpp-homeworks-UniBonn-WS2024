#include "ipb_algorithm.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

namespace ipb {

int accumulate(const named_vector<int>& nvec) {
    return std::accumulate(nvec.std_vector.cbegin(), nvec.std_vector.cend(), 0);
}

int count(const named_vector<int>& nvec, const int& value) {
    return static_cast<int>(std::count_if(nvec.std_vector.cbegin(), nvec.std_vector.cend(),
                                          [value](int num) { return num == value; }));
}

bool all_even(const named_vector<int>& nvec) {
    return std::all_of(nvec.std_vector.cbegin(), nvec.std_vector.cend(),
                       [](int num) { return num % 2 == 0; });
}

void clamp(named_vector<int>& nvec, const int& min, const int& max) {
    for (auto& num : nvec.std_vector) {
        if (num < min) {
            num = min;
        } else if (num > max) {
            num = max;
        }
    }
}

void fill(named_vector<int>& nvec, const int& value) {
    std::fill_n(nvec.std_vector.begin(), nvec.std_vector.size(), value);
}

bool find(const named_vector<int>& nvec, const int& value) {
    return std::any_of(nvec.std_vector.cbegin(), nvec.std_vector.cend(),
                       [value](int num) { return num == value; });
}

void print(const named_vector<int>& nvec) {
    std::cout << nvec.type_name << ": ";
    for (const auto& num : nvec.std_vector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void toupper(named_vector<int>& nvec) {
    for (std::size_t i = 0; i < nvec.type_name.size(); i++) {
        nvec.type_name[i] = static_cast<char>(std::toupper(nvec.name()[i]));
    }
}

void sort(named_vector<int>& nvec) { std::sort(nvec.std_vector.begin(), nvec.std_vector.end()); }

void rotate(named_vector<int>& nvec, const int& n) {
    std::rotate(nvec.std_vector.begin(), nvec.std_vector.begin() + n, nvec.std_vector.end());
}

void reverse(named_vector<int>& nvec) {
    std::reverse(nvec.std_vector.begin(), nvec.std_vector.end());
}

}  // namespace ipb