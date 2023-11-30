#include "ipb_algorithm.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

namespace ipb {

int accumulate(named_vector<int> nvec) {
    return std::accumulate(nvec.std_vector.begin(), nvec.std_vector.end(), 0);
}

int count(named_vector<int> nvec, int value) {
    return static_cast<int>(std::count_if(nvec.std_vector.begin(), nvec.std_vector.end(),
                                          [value](int num) { return num == value; }));
}

bool all_even(named_vector<int> nvec) {
    return std::all_of(nvec.std_vector.begin(), nvec.std_vector.end(),
                       [](int num) { return num % 2 == 0; });
}

void clamp(named_vector<int>& nvec, int min, int max) {
    for (auto& num : nvec.std_vector) {
        if (num < min) {
            num = min;
        } else if (num > max) {
            num = max;
        }
    }
}

void fill(named_vector<int>& nvec, int value) {
    std::fill_n(nvec.std_vector.begin(), nvec.std_vector.size(), value);
}

bool find(named_vector<int> nvec, int value) {
    for (int i = 0; i < nvec.size(); i++) {
        if (nvec.std_vector[i] == value) {
            return true;
        }
    }
    return false;
}

void print(named_vector<int> nvec) {
    for (int i = 0; i < nvec.size(); i++) {
        std::cout << nvec.std_vector[i] << " ";
    }
    std::cout << std::endl;
}

void toupper(named_vector<int>& nvec) {
    for (int i = 0; i < nvec.type_name.size(); i++) {
        nvec.type_name[i] = static_cast<char>(std::toupper(nvec.name()[i]));
    }
}

void sort(named_vector<int>& nvec) { std::sort(nvec.std_vector.begin(), nvec.std_vector.end()); }

void rotate(named_vector<int>& nvec, int n) {
    std::rotate(nvec.std_vector.begin(), nvec.std_vector.begin() + n, nvec.std_vector.end());
}

void reverse(named_vector<int>& nvec) {
    std::reverse(nvec.std_vector.begin(), nvec.std_vector.end());
}

}  // namespace ipb