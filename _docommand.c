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
	int n;

	char **potentials = _fullpath(_patharray(), argumentvectors[0]);

	if (access(argumentvectors[i], F_OK) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(NULL);
		if (pid == 0)
			execve(argumentvectors[i], argumentvectors, NULL);
		return (0);
	}
	for (n = 0; potentials[n] != NULL; n++)
	{
		if (access(potentials[n], F_OK) == 0)
		{
			pid = fork();
			if (pid != 0)
				wait(NULL);
			if (pid == 0)
				execve(potentials[n], argumentvectors, NULL);
			return (0);
		}
	}
	_printf("%s: No such file or directory\n", argumentvectors[i]);
	return (0);
}
