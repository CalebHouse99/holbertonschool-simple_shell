#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - shell program
 * 
 * argc - arguments
 * argv - arguments
 *
 * Return: 0
 */

void lsh_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}

char *lsh_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us

  if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  // We recieved an EOF
    } else  {
      perror("readline");
      exit(EXIT_FAILURE);
    }
  }

  return line;
}

int MAXLINE = 1024;
char propmt[] = "testshell> ";

int main(int argc, char **argv) {
	lsh_loop();

	return EXIT_SUCCESS;
}