#include "slide_line.h"
/**
 * move_left - moves data at index to the least zero
 * @line: Pointer with the integer information
 * @size: size of the array
 * @index: direction to rotate
 * Return: is void
 */
static int move_left(int *line, size_t size, int index)
{
	int pos = 0;

	(void) size;
	pos = index - 1;
	if (pos < 0)
		return (index);
	while (line[pos] == 0)
	{
		if (pos == -1)
			break;
		pos--;
	}
	pos++;
	if (line[pos] == 0 && line[index] != 0)
	{
		line[pos] = line[index];
		line[index] = 0;
		return (pos);
	}
	return (index);
}

/**
 * move_right - moves data at index to the least zero
 * @line: Pointer with the integer information
 * @size: size of the array
 * @index: direction to rotate
 * Return: is void
 */
static int move_right(int *line, size_t size, int index)
{
	size_t pos = 0;

	pos = index + 1;
	if (pos > size)
		return (index);
	while (line[pos] == 0)
	{
		if (pos == size)
			break;
		pos++;
	}
	pos--;
	if (line[pos] == 0 && line[index] != 0)
	{
		line[pos] = line[index];
		line[index] = 0;
		return (pos);
	}
	return (index);
}

/**
 * sum_left - moves data at index to the least zero
 * @line: Pointer with the integer information
 * @size: size of the array
 * @index: direction to rotate
 * Return: is void
 */
static void sum_left(int *line, size_t size, int index)
{
	int pos = 0;

	(void) size;
	pos = index - 1;
	if (pos < 0)
		return;
	while (line[pos] == 0)
	{
		if (pos == 0)
			break;
		pos--;
	}
	if (line[pos] == line[index])
	{
		line[index] = line[index] + line[pos];
		line[pos] = 0;
	}
}

/**
 * sum_right - moves data at index to the least zero
 * @line: Pointer with the integer information
 * @size: size of the array
 * @index: direction to rotate
 * Return: is void
 */
static void sum_right(int *line, size_t size, int index)
{
	size_t pos = 0;

	pos = index + 1;
	if (pos > size)
		return;
	while (line[pos] == 0)
	{
		if (pos == size)
			break;
		pos++;
	}
	if (line[pos] == line[index])
	{
		line[index] = line[index] + line[pos];
		line[pos] = 0;
	}
}

/**
 * slide_line - Rotates one line to the indicated direction
 *
 * @line: Pointer with the integer information
 * @size: size of the array
 * @direction: direction to rotate
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int i = 0;

	if (!line || size == 0)
		return (0);
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < (int) size; i++)
		{
			i = move_left(line, size, i);
			sum_right(line, size, i);
		}
	}
	else
	{
		for (i = (int) size; i >= 0; i--)
		{
			i = move_right(line, size, i);
			sum_left(line, size, i);
		}
	}
	return (1);
}