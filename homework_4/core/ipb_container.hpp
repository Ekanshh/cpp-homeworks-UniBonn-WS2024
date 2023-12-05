#pragma once

#include <string>
#include <vector>

namespace ipb {

template <typename T>

struct named_vector {
    std::string type_name;
    std::vector<T> std_vector;

    std::string name() const;
    std::vector<T> vector() const;
    std::size_t size() const;
    bool empty();
    void resize(const int& size);
    int capacity() const;
    void reserve(const int& size);
};

template <typename T>
std::string named_vector<T>::name() const {
    return type_name;
}

template <typename T>
inline std::vector<T> named_vector<T>::vector() const {
    return std_vector;
}

template <typename T>
std::size_t named_vector<T>::size() const {
    return std_vector.size() + type_name.size();
}

template <typename T>
bool named_vector<T>::empty() {
    return std_vector.empty() || type_name.empty();
}

template <typename T>
void named_vector<T>::resize(const int& size) {
    std_vector.resize(size);
}

template <typename T>
int named_vector<T>::capacity() const {
    return std_vector.capacity();
}

template <typename T>
void named_vector<T>::reserve(const int& size) {
    std_vector.reserve(size);
}
}  // namespace ipb