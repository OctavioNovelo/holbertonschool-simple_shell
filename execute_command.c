#include "main.h"

/**
 * execute_command - Executes a command
 * @command: A string
 */

void execute_command(char *command)
{
    pid_t pid;
    int status;
    char *args[2];
    
    pid = fork();

    if (pid == 0)
      {
        args[0] = command;
        args[1] = NULL;

        if (execv(command, args) == -1)
          {
            perror("/bin/ls: cannot access '/test_hbtn'");
            exit(EXIT_FAILURE);
          }
      }

    else if (pid < 0)
      {
        perror("Fork failed");
	exit(EXIT_FAILURE);
      }
    else
      {
        waitpid(pid, &status, 0);
      }
    
    if (WIFEXITED(status))
      { 
	if (WIFEXITED(status) == EXIT_SUCCESS)
	  {
	    /** Comando exitoso **/
	  }
	else
	  {
	    /** Comando fallido **/
	    printf("%s\n", command);
	  }
      }
    
    else
      {
	printf("%s\n", command);
	exit(EXIT_FAILURE);
      }
}
