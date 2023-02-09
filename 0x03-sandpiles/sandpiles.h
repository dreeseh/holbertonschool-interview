#ifndef _SANDPILES_H
#define _SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

int check_values(int grid[3][3]);
void stable_grid(int grid[3][3]);
void add_2_piles(int grid1[3][3], int grid2[3][3]);
void my_pile_print(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /** _SANDPILES_H */
