#pragma once
#include <iostream>

void print_vector(std::vector<int> a);
int find_min_index(std::vector<int> a,int start_index, int stop_index);
std::vector<int> ssort(std::vector<int> a);
std::vector<int> merge(std::vector<int> left, std::vector<int> right);
std::vector<int> msort(std::vector<int> v);
