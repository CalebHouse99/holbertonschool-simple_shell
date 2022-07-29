#include "main.h"
/**
 * pathify - returns the path in an array
 * @pathpointer: pointer to the path
 * Return: pointer to NULL-terminated array of strings representing the path
 */
char **pathify(char *pathpointer)
{
	char *temppath;
	char **patharray;
	char *dirtocheck;
	int i = 0;
	int dircount = 1;
	int n = 1;

	temppath = _strdup(pathpointer);
	while (temppath[i])
	{
		if (temppath[i] == ':')
			dircount++;
		i++;
	}
	patharray = malloc(sizeof(char *) * (dircount + 1));
	dirtocheck = strtok(temppath, ":\n");
	patharray[0] = dirtocheck;
	while (dirtocheck != NULL)
	{
		dirtocheck = strtok(NULL, ":\n");
		patharray[n] = dirtocheck;
		n++;
	}
	patharray[n] = NULL;
	return(patharray);
}

/**
 * yourpath - finds the path string in the environ
 *
 * Return: pointer to the path string
 */
char *yourpath(void)
{
	size_t i;
	char pathtitle[] = "PATH=";
	char *compary;
	int length;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(pathtitle, environ[i], 5) == 0)
		{
			length = _strlen(environ[i]);
			compary = malloc(sizeof(char) * (length + 1));
			if (compary == NULL)
				return (NULL);
			compary = _strcpy(compary, environ[i]);
			compary += 5;
			return (compary);
		}
	}
	return (NULL);
}

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte, to the buffer pointed to by dest
 *
 * @dest: buffer pointed to
 * @src: string pointed to
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int celltocopy = 0;

	while (src[celltocopy])
	{
		dest[celltocopy] = src[celltocopy];
		celltocopy++;
	}
	dest[celltocopy] = '\0';
	return (dest);
}

/**
 * _strncmp - compares first n bytes of two strings
 * @s1: string
 * @s2: string
 * @n: int, bytes
 * Return: int, how much they differ by
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;
	int difference = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			difference = s1[i] - s2[i];
			break;
		}
	}
	return (difference);
}
/**
 * _strlen - returns the length of a string pointed to by *s
 *
 * @s: string being pointed to
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int lengthvariable;

	for (lengthvariable = 0; *s != '\0'; s++)
	{
		lengthvariable++;
	}
	return (lengthvariable);
}
