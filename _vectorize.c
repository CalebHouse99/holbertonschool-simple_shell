#include "main.h"

/**
 * _vectorize - take argument string and return av vector
 * @buffer: string
 * Return: array of strings
 */
char **_vectorize(char *buffer)
{
	char **av;
	char *argument;
	char *copy;
	int howmanyargs = 0;
	int i = 0;
	char previous = 'a';
	int n = 1;

	copy = _strdup(buffer);
	while (copy[i])
	{
		if (copy[i] == ' ' && previous != ' ')
			howmanyargs++;
		previous = copy[i];
		i++;
	}
	av = malloc(sizeof(*av) * (howmanyargs + 1));
	argument = strtok(copy, " \n");
	av[0] = argument;
	while (argument != NULL)
	{
		argument = strtok(NULL, " \n");
		av[n] = argument;
		n++;
	}
	av[n] = NULL;
	/* free(argument); */
	return (av);
}
