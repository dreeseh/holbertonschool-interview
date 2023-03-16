#include "palindrome.h"

/**
 * is_palindrome - checks whether if a given unsigned integer is a palindrome
 *
 * @n:the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, original = n;

	while (n)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	return (original == reversed);
}
