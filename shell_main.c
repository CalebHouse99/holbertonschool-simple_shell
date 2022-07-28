#include "main.h"

/**
 * shell_main - entry point for shell
 * argc: number of arguments passed
 * argv: array of arguments passed
 * Return: 0 if success
 */
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char *buffer = NULL;
	char leave[] = "exit\n";
	char vire[] = "env\n";
	size_t size = 0;

	if ((argc == 1) && isatty(0))
	{
		_prompt();
		return (0);
	}
	while (1)
	{
		getline(&buffer, &size, stdin);
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
	}
	if (buffer)
	{
		free(buffer);
	}
	return (0);
}