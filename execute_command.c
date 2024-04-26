#include "main.h"
/**
 *
 */
void execute_command(char *command) {
    pid_t pid;
    int status;
    
    pid = fork();

    if (pid == 0) {
       
        if (strcmp(command, "./hbtn_ls") == 0) {
            
            char *args[] = {command, "/var", NULL};
            execv(command, args);
            perror(command); 
            exit(EXIT_FAILURE);
        } else if (strcmp(command, "/bin/ls") == 0) {
            
            if (execl("/bin/cp", "/bin/cp", command, "hbtn_ls", NULL) == -1) {
                perror("/bin/cp");
                exit(EXIT_FAILURE);
            }
        } else {
            printf("Command not found: %s\n", command);
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
