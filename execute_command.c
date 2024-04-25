#include "main.h"

/**
 * execute_command - Executes a command
 * @command: A string
 */

void execute_command(char *command) {
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
            perror(command);
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
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
      }
    if (WIFEXITED(status))
    {
        if (WEXITSTATUS(status) == EXIT_SUCCESS)
        {
	  /** Exit success **/
	}
        else
        {
            printf("Command failed: %s\n", command);
        }
    }
}
