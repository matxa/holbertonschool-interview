#include "slide_line.h"


/**
 * slide_line - slides and merges an array of integers
 * @line: array to slide
 * @size: size of ^ line array
 * @direction: SLIDE_LEFT || SLIDE_RIGHT
 * Return: 1 if success else 0
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t prev;
	size_t current;
	size_t incrementor;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	incrementor = size - 1;
	while (incrementor != 0)
	{
		prev = incrementor;
		current = incrementor - 1;

		if (line[current] == line[prev])
		{
			line[current] = line[prev] + line[current];
			line[prev] = 0;
			push_zeros_to_end(line, size);
		}
		incrementor--;
	}

	if (direction == SLIDE_RIGHT)
	{
		push_zeros_to_start(line, size);
	}

	return (1);
}

/**
 * push_zeros_to_end - push all zero to end of array
 * @arr: array
 * @n: size of array
 */
void push_zeros_to_end(int *arr, size_t n)
{
	size_t count = 0;
	size_t i;

	for (i = 0; i < n; i++)
		if (arr[i] != 0)
			arr[count++] = arr[i];

	while (count < n)
		arr[count++] = 0;
}

/**
 * push_zeros_to_start - push all zero to start of array
 * @arr: array
 * @n: size of array
 */
void push_zeros_to_start(int *arr, size_t n)
{
	int i, j;

	for (j = i = n - 1 ; i >= 0 ; i--)
	{
		if (arr[i] == 0)
			continue;
		arr[j] = arr[i];
		j--;
	}

	while (j >= 0)
	{
		arr[j] = 0;
		j--;
	}
}
