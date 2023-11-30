#ifndef IPB_ALGORITHM_H
#define IPB_ALGORITHM_H

#include "ipb_container.hpp"

namespace ipb {
/**
 * @brief  Returns the sum over all the elements in the data container
 * @param  {named_vector<int>
 * @return {int}
 */
int accumulate(named_vector<int> nvec);
/**
 * @brief  Return how many elements are stored in the container.
 * @param  {named_vector<int>} nvec
 * @param  {int} value
 * @return {int}
 */
int count(named_vector<int> nvec, int value);
/**
 * @brief  Returns true if all the elements in the container are even.
 * @param  {named_vector<int>} nvec
 * @return {bool}
 */
bool all_even(named_vector<int> nvec);
/**
 * @brief  Clamps all the elements in the container to the range [min, max].
 * @param  {named_vector<int>} nvec
 * @param  {int} value
 */
void clamp(named_vector<int>& nvec, int min, int max);
/**
 * @brief  Fills the container with the value.
 * @param  {named_vector<int>} nvec
 * @param  {int} value
 */
void fill(named_vector<int>& nvec, int value);
/**
 * @brief  Returns true if the value is found in the container.
 * @param  {named_vector<int>} nvec
 * @param  {int} value
 * @return {bool}
 */
bool find(named_vector<int> nvec, int value);
/**
 * @brief  Prints all the elements in the container.
 * @param  {named_vector<int>} nvec
 */
void print(named_vector<int> nvec);
/**
 * @brief  Converts all the characters in the name to uppercase.
 * @param  {named_vector<int>} nvec
 */
void toupper(named_vector<int>& nvec);
/**
 * @brief  Sorts the elements in the container.
 * @param  {named_vector<int>} nvec
 */
void sort(named_vector<int>& nvec);
/**
 * @brief  Rotates the elements in the container n times.
 * @param  {named_vector<int>} nvec
 * @param  {int} n
 */
void rotate(named_vector<int>& nvec, int n);
/**
 * @brief  Reverses the elements in the container.
 * @param  {named_vector<int>} nvec
 */
void reverse(named_vector<int>& nvec);

}  // namespace ipb

#endif  // IPB_ALGORITHM_H