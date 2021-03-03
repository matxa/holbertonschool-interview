#include "menger.h"

/**
 * menger - Menger sponge Algo
 * @level: menger level
 * Return: None
 */
void menger(int level)
{
	int depth = level;
	int i, j, dim, d;

	if (depth >= 0)
	{
		for (i = 0, dim = 1; i < depth; i++, dim *= 3)
		{
		}

		for (i = 0; i < dim; i++)
		{
			for (j = 0; j < dim; j++)
			{
				for (d = dim / 3; d; d /= 3)
					if ((i % (d * 3)) / d == 1 && (j % (d * 3)) / d == 1)
						break;
				printf(d ? " " : "#");
			}
			printf("\n");
		}
	}
}
