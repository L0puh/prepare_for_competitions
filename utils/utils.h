#ifndef UTILS_H
#define UTILS_H

#include <cstdio>
#include <exception>
#include <stack>
#include <vector>

void print_array(int array[], int sz);
void print_stack(std::stack<int> temp);
void print_vector(std::vector<int>::iterator b,
                  std::vector<int>::iterator e);
#endif
