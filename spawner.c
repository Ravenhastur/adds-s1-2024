#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char argv[]) {
    if (argc < 2) {
        printf("Usage: %s "command param1 param2 param3 "\n", argv[0]);
        return 1;
    }

    // Parse the command string
    charcommand = strtok(argv[1], " "); // seperate this char array with " "
    char *params = malloc(sizeof(char) * argc);
    if (!params) { // fail to do malloc for params
        printf("Memory allocation error\n");
        return 1;
    }

    int i = 0;
    params[i++] = command;

    char *param = strtok(NULL, " ");
    while (param != NULL) {
        params[i++] = param;
        param = strtok(NULL, " ");
    }
    params[i] = NULL;

    // Start the process
    execvp(command, params); // second para only takes array

    // execvp() returns only if an error occurred
    printf("Failed to execute the command.\n");
    return 1;
}
