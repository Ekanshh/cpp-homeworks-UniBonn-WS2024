#pragma once

#include "ipb_container.hpp"

namespace ipb {

int accumulate(named_vector<int> nvec);
int count(named_vector<int> nvec, int value);
bool all_even(named_vector<int> nvec);
void clamp(named_vector<int>& nvec, int min, int max);
void fill(named_vector<int>& nvec, int value);
bool find(named_vector<int> nvec, int value);
void print(const named_vector<int>& nvec);
void toupper(named_vector<int>& nvec);
void sort(named_vector<int>& nvec);
void rotate(named_vector<int>& nvec, int n);
void reverse(named_vector<int>& nvec);

}  // namespace ipb