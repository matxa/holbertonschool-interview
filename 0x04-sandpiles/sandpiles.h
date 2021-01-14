#ifndef SAND_PILES_H
#define SAND_PILES_H
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int three_d_sum(int grid1[3][3], int grid2[3][3]);
void printgrid(int grid[3][3]);
int is_stable(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SAND_PILES_H */
