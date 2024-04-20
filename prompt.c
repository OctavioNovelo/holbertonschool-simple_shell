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

  printf("root@prueba# ");

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
      
      /** Aqui hay que poner la logica de las funciones **/
      if (strchr(line, '/') != NULL)
	{
            execute_command(line);
	    break;
        }
      else
	{
	  if (strcmp(line, "ls") == 0)
	    {
	      ls();
	      break;
	    }
        }
      if (strcmp(line, "pwd") == 0)
	{
	  execute_command(line);
	}
      free(line);
      line = NULL;
      printf("root@prueba# ");
    }
}
