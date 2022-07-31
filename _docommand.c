#include "main.h"

/**
 * _docommand - do a command
 * @status: int, status
 * @arguments: vector of arguments
 * Return: int, status
 */
int _docommand(char **arguments, int status)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Could not create child process :(");
		return (status);
	}

	if (pid == 0)
		if (execve(arguments[0], arguments, NULL) == -1)
			perror("Could not execute command");
	if (pid > 0)
	{
		wait(&status);
		status = WEXITSTATUS(status);
	}
	return (status);
}
