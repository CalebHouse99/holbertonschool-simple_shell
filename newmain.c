#include "main.h"

/**
 * main - entry point for shell
 *
 * Return: int, status
 */
int main(void)
{
	int i, status = 0, doug = 1, cool = 1;
	size_t size = 0;
	char *buffer = NULL;
	char leave[] = "exit\n", vire[] = "env\n";

	while (doug == cool) /* this is always true */
	{
		if (isatty(0))
			_printf("$ ");
		if (getline(&buffer, &size, stdin) == -1)
			break;
		if (buffer[0] == '\n')
			continue;
		if (_strcmp(buffer, leave) == 0)
		{
			free(buffer);
			fflush(stdin);
			exit(errno);
		}
		if (_strcmp(buffer, vire) == 0)
		{
			printenv();
			continue;
		}
		for (i = 0; buffer[i] != '\n'; i++)
			if (buffer[i] != ' ')
			{
				status = _interpret_commands(status, buffer);
				break;
			}
	}
	free(buffer);
	return (status);
}
