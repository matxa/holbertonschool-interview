#include "sort.h"

/**
 * radix_sort - redix sort
 * @array: array
 * @size: size of array
 * Return: VOID
 *
 */
void radix_sort(int *array, size_t size)
{
	int bucket[10][10], bucket_cnt[10];
	size_t i, j, k, r, NOP = 0, divisor = 1, lar, pass;

	lar = get_max(array, size);

	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}

	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
		{
			bucket_cnt[i] = 0;
		}
		for (i = 0; i < size; i++)
		{
			r = (array[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < (size_t)bucket_cnt[k]; j++)
			{
				array[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10;
		print_array(array, size);
	}
}

/**
 * get_max - get max
 * @arr: array
 * @n: size
 * Return: int
 */
int get_max(int arr[], size_t n)
{
	int max = arr[0];

	for (size_t i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	return (max);
}
