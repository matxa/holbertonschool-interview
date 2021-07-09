#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void radix_sort(int *array, size_t size);
void sort_radix_helper(int *array_to_sort, size_t size, size_t significant_d);
void print_array(const int *array, size_t size);

#endif
