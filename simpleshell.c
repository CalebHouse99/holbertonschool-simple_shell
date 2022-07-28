#include "main.h"
/**
 * main - get going
 * Return: 0 on success, 1 otherwise
 */
int main(void)
{
	/* char **command; */
	char *buffer = NULL;
	char leave[] = "exit\n";
	char vire[] = "env\n";
	size_t size = 0;

	while (1)
	{
		_printf("$ ");
		getline(&buffer, &size, stdin);
		if (buffer[0] == '\n')
		{
			continue;
		}
		if (_strcmp(buffer, leave) == 0)
			break;
		if (_strcmp(buffer, vire) == 0)
		{
			printenv();
			continue;
		}
		strtok(buffer, " ");
	}
	free(buffer);
	return (0);
}
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
