#pragma once

#include <string>
#include <tuple>
#include <vector>

namespace ipb {

template <typename T>
struct named_vector {
    std::string type_name;
    std::vector<T> std_vector;
    std::string name();
    std::vector<T> vector();
    std::size_t size();
    bool empty();
    void resize(int size);
    int capacity();
    void reserve(int size);
};
}  // namespace ipb