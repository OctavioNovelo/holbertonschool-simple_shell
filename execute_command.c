#include "main.h"

/**
 * execute_command - Executes a command
 * @command: A string
 */

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)
      {
	if (execv(command, (char *const []){command, NULL}) == -1)
	  {
            perror("Error executing command");
	    exit(EXIT_FAILURE);
	  }
      }

    else if (pid < 0)
      {
        perror("Fork failed");
      }
    else
      {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
