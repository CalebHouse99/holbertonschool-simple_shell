#include "main.h"

/**
 * _look_for_a_program - looks for a program by link or path
 * @name: name of the file as given
 * Return: string, full address (whether given and verified or found in path)
 * or NULL if not found
 */
char *_look_for_a_program(char *name)
{
	char *pathstring, *temp, *directory;

	if (access(name, F_OK) == 0)
		return (name);
	pathstring = yourpath();
	directory = strtok(pathstring, ":");
	while (directory)
	{
		directory = _strdup(directory);
		temp = str_concat(directory, "/");
		pathstring = str_concat(temp, name);
		if (access(pathstring, F_OK) == 0)
		{
			free(directory);
			free(temp);
			return (pathstring);
		}
		directory = strtok(NULL, ":\n");
	}
	_printf("%s: No such file or directory\n", name);
	if(pathstring)
		free(pathstring);
	if (temp)
		free(temp);
	if (directory)
		free(directory);
	return (NULL);
}
