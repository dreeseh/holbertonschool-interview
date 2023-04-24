#include "menger.h"

/**
 * menger - draws a 2-D menger square
 * @level: the level of the Menger Sponge to draw
 * Return: is void
 */
void menger(int level)
{
	int n, row, col, row2, col2, c;

	n = pow(3, level);
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			row2 = row;
			col2 = col;
			c = '#';
			while (row2 || col2)
			{
				if (row2 % 3 == 1 && col2 % 3 == 1)
					c = ' ';
				row2 /= 3;
				col2 /= 3;
			}
			putchar(c);
		}
		printf("\n");
	}
}
