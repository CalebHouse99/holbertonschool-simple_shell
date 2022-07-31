#include "main.h"
/**
 * printenv - prints the environment
 *
 * Return: nothing
 */
void printenv(void)
{
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
