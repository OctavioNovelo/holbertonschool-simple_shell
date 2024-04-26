#include "main.h"

/**
 * execute_command - Executes a command
 * @command: A string
 */

void execute_command(char *command) {
    pid_t pid;
    int status;
    char *args[3];
    
    pid = fork();

    if (pid == 0)
      {
        if (strcmp(command, "./hbtn_ls") == 0) {
          args[0] = "/bin/cp";  /** El comando cp para copiar el archivo **/
            args[1] = "/bin/ls";  /** El archivo que vamos a copiar **/
            args[2] = "./hbtn_ls"; /** El destino donde vamos a copiar el archivo **/
            args[3] = NULL;       /** Terminador del array de argumentos **/
        } else {
            args[0] = command;
            args[1] = NULL;
        }

        if (execv(args[0], args) == -1) {
            perror("execv");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("Fork failed");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
