#pragma once

#include "ipb_container.hpp"

namespace ipb {

int accumulate(const named_vector<int>& nvec);
int count(const named_vector<int>& nvec, const int& value);
bool all_even(const named_vector<int>& nvec);
void clamp(named_vector<int>& nvec, const int& min, const int& max);
void fill(named_vector<int>& nvec, const int& value);
bool find(const named_vector<int>& nvec, const int& value);
void print(const named_vector<int>& nvec);
void toupper(named_vector<int>& nvec);
void sort(named_vector<int>& nvec);
void rotate(named_vector<int>& nvec, const int& n);
void reverse(named_vector<int>& nvec);

}  // namespace ipb