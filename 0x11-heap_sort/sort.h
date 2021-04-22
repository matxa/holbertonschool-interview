#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heapify(int *array, size_t n, size_t i);
void swap(int *x, int *y);
void heap_sort(int *array, size_t size);

#endif
