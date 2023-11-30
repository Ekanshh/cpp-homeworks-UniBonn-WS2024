#include "ipb_container.hpp"

namespace ipb {

template struct ipb::named_vector<float>;
template struct ipb::named_vector<int>;
template struct ipb::named_vector<char>;
template struct ipb::named_vector<std::string>;
template struct ipb::named_vector<double>;
template struct ipb::named_vector<std::tuple<int, float>>;

template <typename T>
std::string named_vector<T>::name() {
    return type_name;
}

template <typename T>
inline std::vector<T> named_vector<T>::vector() {
    return std_vector;
}

template <typename T>
int named_vector<T>::size() {
    return std_vector.size() + type_name.size();
}

template <typename T>
bool named_vector<T>::empty() {
    return std_vector.empty() || type_name.empty();
}

template <typename T>
void named_vector<T>::resize(int size) {
    std_vector.resize(size);
}

template <typename T>
int named_vector<T>::capacity() {
    return std_vector.capacity();
}

template <typename T>
void named_vector<T>::reserve(int size) {
    std_vector.reserve(size);
}
}  // namespace ipb
