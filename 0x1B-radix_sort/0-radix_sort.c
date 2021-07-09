#include "sort.h"


/**
 * sort_radix_helper - radix sort
 * @array_to_sort: array to sort
 * @size: size of array
 * @significant_d: significant digit
 */
void sort_radix_helper(int *array_to_sort, size_t size, size_t significant_d)
{
	size_t index, temp_index = 0, curr_index = 0, digits[10] = {0};
	int temp_modulo, curr_i, token, *at_index[10], div = significant_d / 10;

	while (temp_index < size)
	{
		temp_modulo = array_to_sort[temp_index] % significant_d;
		curr_i = (temp_modulo) / (div);
		digits[curr_i] = digits[curr_i] + 1;
		temp_index++;
	}
	if (digits[0] == size)
	{
		return;
	}
	temp_index = 0; while (temp_index < 10)
	{
		at_index[temp_index] = malloc(digits[temp_index] * sizeof(int));
		temp_index++;
	}
	temp_index = 0; while (temp_index < 10)
	{
		token = 0;
		curr_index = 0;
		while (curr_index < size)
		{
			index = array_to_sort[curr_index] % significant_d;
			if (((index) / (div)) == temp_index)
			{
				at_index[temp_index][token] = array_to_sort[curr_index];
				token++;
			}
		curr_index++;
		}
	temp_index++;
	}
	token = 0;
	temp_index = 0;
	while (temp_index < 10)
	{
		curr_index = 0;
		while (curr_index < digits[temp_index])
		{
			array_to_sort[token] = at_index[temp_index][curr_index];
			token++;
			curr_index++;
		}
		temp_index++;
	}
	print_array((const int *)array_to_sort, size);
	temp_index = 0;
	while (temp_index < 10)
	{
		free(at_index[temp_index]);
		temp_index++;
	}
	sort_radix_helper(array_to_sort, size, significant_d * 10);
}

/**
 * radix_sort - Radix sort
 * @array: only integers greater than zero
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	if (array == NULL)
	{
		return;
	}
	sort_radix_helper(array, size, 10);
}
