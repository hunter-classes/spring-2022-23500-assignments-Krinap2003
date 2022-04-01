#pragma once
#include <iostream>

void print_vector(std::vector<int> a);
int find_min_index(std::vector<int> a,int start_index, int stop_index);
std::vector<int> ssort(std::vector<int> a);
std::vector<int> merge(std::vector<int> left, std::vector<int> right);
std::vector<int> msort(std::vector<int> v);
int count(std::vector<int> v, int value);
int largest(std::vector<int> v);
int mode(std::vector<int> v);
int mode2(std::vector<int> v);
std::vector<int> qsort(std::vector<int> list);
void print_help(char *command_name);
std::vector<int> qsort2(std::vector<int> list, int low, int high);