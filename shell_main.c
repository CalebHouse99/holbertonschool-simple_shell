#include "main.h"

/**
 * main - entry point for shell
 * @argc: number of arguments passed
 * @argv: array of arguments passed
 * Return: 0 if success
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	char *buffer = NULL;
	char leave[] = "exit\n";
	char vire[] = "env\n";
	size_t size = 0;
	char **arguments;

	if ((argc == 1) && isatty(0))
	{
		_prompt();
		return (0);
	}
	while (getline(&buffer, &size, stdin) != -1)
	{
		if (buffer[0] == '\n')
		{
			free(buffer);
			continue;
		}
		if (_strcmp(buffer, leave) == 0)
			break;
		if (_strcmp(buffer, vire) == 0)
		{
			printenv();
			free(buffer);
			continue;
		}
		else
		{
			arguments = _vectorize(buffer);
			_docommand(arguments);
			continue;
		}
	}
/* 	_freeargs(arguments); */
	if (buffer)
	{
		free(buffer);
	}
	return (0);
}
