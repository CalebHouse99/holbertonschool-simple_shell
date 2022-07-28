#include "main.h"

/**
 * _docommand - do a command
 * @argumentvectors: vector of arguments
 * Return: 0 on success
 */
int _docommand(char **argumentvectors)
{
	pid_t pid;
	int i = 0;

	if (access(argumentvectors[i], F_OK) == 0)
	{
		pid = fork();
		if (pid != 0)
		{
			wait(NULL);
		}
		if (pid == 0)
		{
			execve(argumentvectors[i], argumentvectors, NULL);
		}
		return (0);
	}
	if (access(argumentvectors[i], F_OK != 0))
			_printf("%s: No such file or directory\n", argumentvectors[i]);
	return (0);
}
