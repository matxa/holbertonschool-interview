#include "sort.h"

void heapify(int *array, size_t n, size_t i)
{
	size_t largest = i;
	size_t l = 2 * i + 1;
	size_t r = 2 * i + 2;
	int temp;

	if (l < n && array[l] > array[largest])
		largest = l;

	if (r < n && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		heapify(array, n, largest);
	}
}

void heap_sort(int *array, size_t size)
{
	int i;
	int temp;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i);
		print_array(array, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0);
		print_array(array, size);
	}
}
