#include "main.h"

/**
 * _patharray - make an array out of the path
 *
 * Return: pointer to the array
 */
char **_patharray(void)
{
	int i = 1;
	char *thepath;
	char **patharray;
	char *directory;
	int colons = 0;
	int n;

	thepath = _strdup(yourpath());

	for (n = 0; thepath[n] != '\0'; n++)
	{
		if (thepath[n] == ':')
			colons++;
	}
	patharray = malloc(sizeof(char *) * (colons + 2));
	directory = strtok(thepath, ":");
	patharray[0] = directory;
	while (directory != NULL)
	{
		directory = strtok(NULL, ":");
		patharray[i] = directory;
		i++;
	}
	patharray[i] = NULL;
	return (patharray);
}
/**
 * _fullpath - the full path
 * @patharray: array of strings
 * @programname: the name of the program
 * Return: array of string
 */
char **_fullpath(char **patharray, char *programname)
{
	char **completepath;
	char *filesuffix;
	int i;
	int n = 0;
	char slashy[] = "/";

	char *filesuffix = str_concat(slashy, _strdup(programname));

	while (*patharray)
		n++;
	completepath = malloc(sizeof(char *) * (n + 2));
	for (i = 0; i < n; i++)
	{
		completepath[i] = str_concat(patharray[i], filesuffix);
	}
	completepath[i] = NULL;
	return (completepath);
}
