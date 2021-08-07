#include "holberton.h"

/**
 * wildcmp - compare two strings recursevely
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if identical else 0
 */
int wildcmp(char *s1, char *s2)
{
	int cmp = 0;

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
	{
		return wildcmp(s1 + 1, s2 + 1);
	}
	if (*s2 == '*')
	{
		if (*s1 != '\0')
		{
			cmp = wildcmp(s1 + 1, s2);
		}
		return (wildcmp(s1, s2 + 1) || cmp);
	}
	return (0);
}
