#include "main.h"
#include <string.h>

void prompt() {
    char *line = NULL;
    size_t len = 0;
    ssize_t str;

    while (1) {
        printf("$ ");
        str = getline(&line, &len, stdin);

        if (str == -1) {
            break;
        }

	if (line[str - 1] == '\n') {
            line[str - 1] = '\0';
        }
	if (strcmp(line, "EXIT") == 0 || strcmp(line, "exit") == 0) {
            break;
        }
	char *token = strtok(line, " ");
	 char *args[100];
	 int i = 0;

	 while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
	 args[i] = NULL;
	 execute_command(args);

	 }

    free(line);
    line = NULL;
}
