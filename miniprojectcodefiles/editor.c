#include <stdio.h>
#include <string.h>

void text_editor(char *filename) {
    // 1. Check if file opened successfully
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[256];
    printf("Entering Editor (Type 'SAVE' on a new line to finish):\n");

    while (1) {
        // 2. Safely read input
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) break;

        // 3. Strict 'SAVE' check: Ensures it doesn't trigger on "SAVED" or "SAVE ME"
        if (strcmp(buffer, "SAVE\n") == 0) {
            break;
        }

        // 4. Write to file and check for errors
        if (fprintf(fp, "%s", buffer) < 0) {
            printf("Error writing to file.\n");
            break;
        }
    }

    fclose(fp);
    printf("File '%s' saved successfully.\n", filename);
}
