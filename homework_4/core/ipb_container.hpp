#ifndef IPB_CONTAINER_H_
#define IPB_CONTAINER_H_

#include <string>
#include <tuple>
#include <vector>

namespace ipb {

/**
@brief A `named_vector` container that stores a vector with a name.
*/
template <typename T>
struct named_vector {
    /**
     * @brief The name of the vector.
     */
    std::string type_name;
    /**
     * @brief The vector itself.
     */
    std::vector<T> std_vector;
    /**
     * @brief Returns the name of the vector.
     */
    std::string name();
    /**
     * @brief Returns the vector itself.
     */
    std::vector<T> vector();
    /**
     * @brief Returns the size of the vector.
     */
    std::size_t size();
    /**
     * @brief Returns true if the vector is empty.
     */
    bool empty();
    /**
     * @brief Resizes the vector.
     * @param size The new size of the vector.
     */
    void resize(int size);
    /**
     * @brief Returns the capacity of the vector.
     */
    int capacity();
    /**
     * @brief Reserves the vector.
     * @param size The size to reserve.
     */
    void reserve(int size);
};
}  // namespace ipb

#endif  // IPB_CONTAINER_H_