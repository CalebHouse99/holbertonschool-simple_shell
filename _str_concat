#include "main.h"
#include <stdlib.h>

/**
 * str_concat - puts ones string after the other and terminates w/ NULL byte
 *
 * @s1: string
 * @s2: string
 *
 * Return: Return pointer to beginning of new string (or NULL if can't)
 */
char *str_concat(char *s1, char *s2)
{
	char *new;
	int x, y, newlength, s1count = 0, s2count = 0;

	if (s1 == NULL)
		s1count = 0;
	else
		while (s1[s1count])
		s1count++;
	if (s2 == NULL)
		s2count = 0;
	else
		while (s2[s2count])
		s2count++;
	newlength = s1count + s2count + 1;
	new = (char *)malloc(newlength * sizeof(char));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	for (x = 0; x < s1count; x++)
	{
		new[x] = s1[x];
	}
	for (y = 0; y < s2count; y++)
	{
		new[x] = s2[y];
		x++;
	}
	new[x] = '\0';
	return (new);
}
