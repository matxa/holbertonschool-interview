#include "palindrome.h"


/**
 * is_palindrome - check if interger is a palindrome
 * @n: integer
 * Return: 1 if True else 0
 */
int is_palindrome(unsigned long n)
{
	if (n == reverse_num(n))
		return (1);

	return (0);
}


/**
 * reverse_num - reverse number
 * @n: integer
 * Return: reversed num
 */
unsigned long reverse_num(unsigned long n)
{
	static int reverse_n = 0, rem;

	if (n != 0)
	{
		rem = n % 10;
		reverse_n = reverse_n * 10 + rem;
		reverse_num(n / 10);
	}

	return (reverse_n);
}
