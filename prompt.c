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
  char *token;
  while (1)
    {
      str = getline(&line, &len, stdin);

      if (str == -1)
	{
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

      token = strtok(line, " ");
      while (token != NULL)
	{
	  /** Aqui hay que poner la logica de las funciones **/
	   if (strcmp(token, "ls") == 0 || strcmp(token, "pwd") == 0)
            {
                execute_command(token);
            }
            else if (strchr(token, '/') != NULL)
            {
                execute_command(token);
            }
            else
            {
                printf("Command not found: %s\n", token);
            }
            token = strtok(NULL, " ");
	}
    }

  free(line);
  line = NULL;
}
