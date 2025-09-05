#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"

void print_menu() {
    printf("\n=== Linux File Operations Lab ===\n");
    printf("1. Create and write to file\n");
    printf("2. Read file contents\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

int main() {
    int choice;
    char filename[256], content[1024];

    printf("Linux File Operations Lab\n");
    printf("This program demonstrates file operations using system calls\n\n");

    while(1) {
        print_menu();
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {
            case 1:
                printf("Enter filename to create: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // remove newline

                printf("Enter content to write: ");
                fgets(content, sizeof(content), stdin);
                content[strcspn(content, "\n")] = 0; // remove newline

                if(create_and_write_file(filename, content) == 0) {
                    printf("SUCCESS: File '%s' created and written successfully!\n", filename);
                } else {
                    printf("ERROR: Failed to create file '%s'\n", filename);
                }
                break;

            case 2:
                printf("Enter filename to read: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // remove newline

                if(read_file_contents(filename) == 0) {
                    printf("SUCCESS: File '%s' read successfully!\n", filename);
                } else {
                    printf("ERROR: Failed to read file '%s'\n", filename);
                }
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}