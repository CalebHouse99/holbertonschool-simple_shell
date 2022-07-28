#include "main.h"
/**
 * _freeargs - frees an array of arguments
 * @arguments: array of arguments 
 * Return: 0 on success
 */
int _freeargs(char **arguments)
{
	int i = 0;

	while (arguments[i])
	{
		i++;
	}
	while (i > 0)
	{
		i--;
		free(arguments[i]);
	}
	return (0);
}
