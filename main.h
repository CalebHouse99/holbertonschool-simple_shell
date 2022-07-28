#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

int _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);
int _strcmp(char *s1, char *s2);
void printenv(void);
char *yourpath(void);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);
int _prompt(void);

#endif /* MAIN_H */
