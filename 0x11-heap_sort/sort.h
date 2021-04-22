#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void swap(int *left, int *right, int *array, size_t size);
void swap(int *v, int *r, int *array, size_t x);
void heap_sort(int *array, size_t size);

#endif
