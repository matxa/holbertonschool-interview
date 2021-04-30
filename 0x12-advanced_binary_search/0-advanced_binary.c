#include "search_algos.h"
/**
 * print_array - print array
 * @array: array
 * @start: start index
 * @end: end of array
 * Return: Void
 */
void print_array(int *array, size_t start, size_t end)
{
	printf("Searching in array: ");
	while (start < end)
	{
		printf("%i, ", array[start]);
		start++;
	}
	printf("%i\n", array[start]);
}
/**
 * binary_search - recursive binary search of array
 * @array: array to search
 * @first_num: first elements of array
 * @second_num: second elements of array
 * @value: value
 * Return: index of value or [ -1 ]
 */
int binary_search(int *array, int first_num, int second_num, int value)
{
	int mid;

	print_array(array, first_num, second_num);

	mid = (second_num - first_num) / 2 + first_num;

	if (first_num == second_num)
		return (-1);

	if (array[mid] == value && array[mid - 1] != value)
		return (mid);

	if (array[mid] >= value)
		return (binary_search(array, first_num, mid, value));

	if (array[mid] <= value)
		return (binary_search(array, mid + 1, second_num, value));

	return (-1);
}
/**
 * advanced_binary - advanced search
 * @array: array to search
 * @size: size
 * @value: value
 * Return: index of value or [ -1 ]
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (binary_search(array, 0, size - 1, value));
}
