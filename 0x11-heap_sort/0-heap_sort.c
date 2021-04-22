#include "sort.h"

/**
 * swap - swapping function
 * @array: array to be printed
 * @left: left value
 * @right: right value
 * @size: size of array
 * Return: void
 */
void swap(int *left, int *right, int *array, size_t size)
{
	int temp = *left;
	*left = *right;
	*right = temp;
	print_array(array, size);
}

/**
 * heapify - heapify function
 * @array: array of numbers
 * @h: h
 * @b: b
 * @size: size of array
 * Return: void
 */
void heapify(int *array, int h, int b, size_t size)
{
	int biggest = b;
	int left = 2 * b + 1;
	int right = 2 * b + 2;

	if (left < h && array[left] > array[biggest])
		biggest = left;

	if (right < h && array[right] > array[biggest])
		biggest = right;

	if (biggest != b)
	{
		swap(&array[b], &array[biggest], array, size);
		heapify(array, h, biggest, size);
	}
}

/**
 * heap_sort - heap sort algorithm
 * @array: array
 * @size: size of array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t b;

	if (array == NULL)
		return;

	for (b = size / 2; b > 0; b--)
		heapify(array, size, b - 1, size);

	for (b = size - 1; b > 0; b--)
	{
		swap(&array[0], &array[b], array, size);
		heapify(array, b, 0, size);
	}
}
