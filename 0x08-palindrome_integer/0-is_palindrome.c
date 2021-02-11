#include "palindrome.h"


/**
 * is_palindrome - check if interger is a palindrome
 * @n: integer
 * Return: 1 if True else 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0;
	unsigned long rem;
	unsigned long ori_num;

	ori_num = n;

	while (n != 0)
	{
		rem = n % 10;
		rev = rev * 10 + rem;
		n /= 10;
	}

	if (ori_num == rev)
		return (1);
	else
		return (0);
}
