#include "main.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: the first string
 * @s2: the second string
 *
 * Return: an  integer less than, equal to, or greater than zero if s1
 * is found, respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if ((s1[i] == '\0') && (s2[i] == '\0'))
		{
			return (0);
		}
	}
	return (s1[i] - s2[i]);
}
