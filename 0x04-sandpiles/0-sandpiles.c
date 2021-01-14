#include "sandpiles.h"

/**
 * printgrid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void printgrid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}


/**
 * two_d_sum - sum two three dimentional grids
 * @grid1: grid one
 * @grid2: grid two
 *
 */
void two_d_sum(int grid1[3][3], int grid2[3][3])
{

	int row, index;

	for (row = 0; row < 3; row++)
		for (index = 0; index < 3; index++)
			grid1[row][index] += grid2[row][index];
}


/**
 * is_stable - check if grid is stable no number is bigger than 3
 * @grid: 3x3 grid
 * Return: 1 if True else 0
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}

	return (1);
}


/**
 * tumbler - add one to index's neighbor
 * @row: sub array
 * @index: index at row
 * @grid: 3x3 grid
 *
 */
void tumbler(int grid[3][3], int row, int index)
{
	/* top */
	if (row - 1 >= 0)
		grid[row - 1][index] += 1;
	/* bottom */
	if (row + 1 < 3)
		grid[row + 1][index] += 1;
	/* left */
	if (index - 1 >= 0)
		grid[row][index - 1] += 1;
	/* right */
	if (index + 1 < 3)
		grid[row][index + 1] += 1;
}


/**
 * sandpiles_sum - sum sandpiles
 * @grid1: grid 3*3
 * @grid2: grid 3*3
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int n, index, row = 0;

	two_d_sum(grid1, grid2);

	while (is_stable(grid1) != 1)
	{
		printf("=\n");
		printgrid(grid1);
		for (row = 0; row < 3; row++)
			for (index = 0; index < 3; index++)
			{
				n = grid1[row][index];
				if (n > 3)
				{
					tumbler(grid1, row, index);
					grid1[row][index] -= 4;
				}
			}
	}
}
