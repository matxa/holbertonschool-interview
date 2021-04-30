#include "search_algos.h"

/**
 * binary_search - linear search function
 * @array: array to iterate
 * @size: size of the array
 * @value: value to seach for in the array
 * Return: index
 */
int binary_search(int *array, size_t size, int value)
{
	size_t start = 0;
	size_t mid;
	size_t end = size - 1;
	size_t i;

	if (array == NULL)
		return (-1);

	while (start <= end)
	{
		printf("Searching in array: ");

		for (i = start; i < end + 1; i++)
		{
			if (i < end)
			{
				printf("%d", array[i]);
				printf(", ");
			}
			else
			{
				printf("%d", array[i]);
				printf("\n");
			}
		}

		mid = (start + end) / 2;
		if (array[mid] == value)
			return (mid);
		if (value < array[mid])
			end = mid - 1;
		if (value > array[mid])
			start = mid + 1;
	}
	return (-1);
}

/**
 * advanced_binary - advanced search
 * @array: array to search
 * @size: size of array
 * @value: value to return
 * Return: index of 1st value in array or -1 on fail
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (binary_search(array, size, value));
}
