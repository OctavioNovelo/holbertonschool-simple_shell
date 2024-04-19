#include "main.h"
/**
 *prompt - print the prompt
 *
 */
void prompt()
{
  char *line = NULL;
  size_t len = 0;
  ssize_t str;
  while (1)
    {
      printf("root@prueba# ");
      str = getline(&line, &len, stdin);

      if (str == -1)
	{
	  printf("Error reading input\n");
	  break;
	}

      if (line[str - 1] == '\n')
      {
	line[str - 1] = '\0';
      }

      if (strcmp(line, "EXIT") == 0 || strcmp(line, "exit") == 0)
	{
	  break;
	}
      /** Aqui hay que poner la logica de las funciones **/
      if (strchr(line, '/') != NULL) {
            execute_command(line);
        }
      else
	{
	  if (strcmp(line, "ls") == 0)
	    {
	    execute_command(line);
	    }
        }
      if (strcmp(line, "pwd") == 0)
	{
	  execute_command(line);
	}
    }
printf("You entered: %s\n", line);
free(line);
}
