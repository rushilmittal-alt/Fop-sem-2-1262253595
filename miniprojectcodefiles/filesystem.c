#include <stdio.h>
#include <dirent.h>
#include <string.h>

// 1. Improved File Creation
void create_file(const char *name) {
    if (name == NULL) return;

    FILE *fp = fopen(name, "w");
    if (fp) {
        printf("File '%s' created successfully.\n", name);
        fclose(fp);
    } else {
        perror("Error creating file"); // Added error reporting
    }
}

// 2. Improved File Deletion
void delete_file(const char *name) {
    if (name == NULL) return;
    if (remove(name) == 0) {
        printf("File '%s' deleted successfully.\n", name);
    } else {
        perror("Error deleting file");
    }
}

void list_files() {
    struct dirent *de;
    DIR *dr = opendir(".");

    if (dr == NULL) {
        perror("Could not open current directory");
        return;
    }

    printf("\n--- Files in Directory ---\n");
    while ((de = readdir(dr)) != NULL) {
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }
        printf("%s  ", de->d_name);
    }
    printf("\n--------------------------\n");

    closedir(dr);
}
