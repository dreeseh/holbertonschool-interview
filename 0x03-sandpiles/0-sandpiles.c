#include "sandpiles.h"

/**
 * check_values - checks the values in the grid
 * @grid: the grid to check
 * Return: 0 for stable, 1 for not stable
 */
int check_values(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			if (grid[x][y] > 3)
				return (0);
	return (1);
}

/**
 * stable_grid - checks if grid is stable
 * @grid: the grid to check
 * Return: is void
 */
void stable_grid(int grid[3][3])
{
	int i, j;
	int three_by_3[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			three_by_3[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
			{
				grid[i][j] -= 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					three_by_3[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					three_by_3[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					three_by_3[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					three_by_3[i][j + 1] += 1;
			}
		}
	}
	add_2_piles(grid, three_by_3);
}


/**
 * add_2_piles - adds two sandpiles
 * @grid1: first sandpile to add
 * @grid2: second sandpile to add
 * Return: is void
 */
void add_2_piles(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];
}

/**
 * my_pile_print - prints sandpiles to terminal
 * @grid: the grid with the sandpiles to print
 * Return: is void
 */
void my_pile_print(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (y)
				printf(" ");
			printf("%d", grid[x][y]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Complete sum 2 sandpiles
 * @grid1: first stable sandpile
 * @grid2: second stable sandpile
 * Return: is void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_2_piles(grid1, grid2);

	while (!check_values(grid1))
	{
		printf("=\n");
		my_pile_print(grid1);
		stable_grid(grid1);
	}
}
