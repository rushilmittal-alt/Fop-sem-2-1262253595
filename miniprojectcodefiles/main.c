#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "filesystem.c" // Member 2
#include "editor.c"     // Member 3
#include "utlity.c"     // Member 4

int main() {
    char input[100];
    char *cmd, *arg;

    printf("Welcome to MiniOS v1.0\n");
    printf("Type 'help' for a list of commands.\n");

    while (1) {
        printf("MiniOS_User> ");
        if (!fgets(input, sizeof(input), stdin)) break;

        // Clean newline and split command from argument
        input[strcspn(input, "\n")] = 0;
        cmd = strtok(input, " ");
        arg = strtok(NULL, " ");

        if (cmd == NULL) continue;

        if (strcmp(cmd, "exit") == 0) {
            break;
        } else if (strcmp(cmd, "help") == 0) {
            printf("Commands: ls, touch, rm, edit, calc, info, exit\n");
        } else if (strcmp(cmd, "ls") == 0) {
            list_files();
        } else if (strcmp(cmd, "touch") == 0 && arg) {
            create_file(arg);
        } else if (strcmp(cmd, "rm") == 0 && arg) {
            delete_file(arg);
        } else if (strcmp(cmd, "edit") == 0 && arg) {
            text_editor(arg);
        } else if (strcmp(cmd, "calc") == 0) {
            simple_calc();
        } else if (strcmp(cmd, "info") == 0) {
            sys_info();
        } else {
            printf("Error: Command '%s' not found.\n", cmd);
        }
    }

    return 0;
}
