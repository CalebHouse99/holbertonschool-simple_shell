#include "main.h"

/**
 * _interpret_commands - parses and executes commands from getline
 * @status: int, represents shell status
 * @buffer: string of commands as given to shell
 * Return: int representing status (0 on success)
 */
int _interpret_commands(int status, char *buffer)
{
	char *arguments[50], *token, *command, delimiter[] = {' ', '\n'};
	int index;

	token = strtok(buffer, delimiter);
	for (index = 0; token != NULL; index++)
	{
		arguments[index] = token;
		token = strtok(NULL, delimiter);
	}
	arguments[index] = NULL; /* we want the last element to be a NULL ptr */
	command = _look_for_a_program(arguments[0]);
	if (!command)
		return (status);
	if (_strcmp(command, arguments[0]) != 0)
	{
		arguments[0] = command;
	}
	status = _docommand(arguments, status);
	free(command);
	free(token);
	return (status);
}
