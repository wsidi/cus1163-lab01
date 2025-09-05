# Lab 1: Linux File Operations with System Calls

#### Learning Objectives

- Implement file creation and writing using the `open()` and `write()` system calls with appropriate flags and
  permissions.
- Read file contents using the `open()` and `read()` system calls, processing data in chunks.
- Practice robust file descriptor management and error handling.
- Understand how user-level programs interact with the kernel for basic file I/O.

#### Prerequisites

- Basic C programming knowledge.
- Familiarity with compiling C programs using `gcc`.
- Comfort with the Linux terminal and command line.
- Understanding of basic C data types, arrays, and strings.

#### Introduction

This lab introduces you to core Linux file operations in C, using direct system calls such as `open()`, `write()`, and
`read()`. You will build hands-on knowledge of how operating systems manage files at a low level, preparing you for
further systems programming and OS concepts.

You'll work with a menu-driven application that allows users to create and write files, read file contents, and manage
file operations using low-level system calls instead of high-level C library functions.

#### Lab File Structure

**main.c (PROVIDED - Complete)**  
This file contains the main entry point for your lab application. It presents a simple menu-driven interface for the
user, allowing them to select between creating/writing a file, reading a file, or exiting the program. It handles user
input, calls the functions implemented in `file_operations.c`, and prints results and status messages. This file is
fully implemented—you do not need to modify it.

```c++
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
```

**file_operations.c (TEMPLATE - TO COMPLETE)**  
This file contains the core logic for your file operations. You will implement the actual system calls to create, write,
and read files. The two main functions, `create_and_write_file()` and `read_file_contents()`, are provided with comments
indicating where you must fill in the missing code. Carefully follow the instructions and hints to complete the required
functionality using system calls. This is the main focus of your lab work.

```c++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "file_operations.h"

int create_and_write_file(const char *filename, const char *content) {
    // TODO: Declare an integer 'fd' for the file descriptor.
    // TODO: Declare a variable 'bytes_written' of type ssize_t to store how many bytes are written.

    // TODO: Print a message showing which file is being created.
    // TODO: Print a message showing what content will be written.

    // TODO: Open or create the file for writing using the open() system call.
    // TODO: Use flags O_CREAT | O_WRONLY | O_TRUNC and permissions 0644.
    // TODO: Check if open() failed (fd == -1). If so, print an error using perror and return -1.

    // TODO: Print the file descriptor value.

    // TODO: Write the content to the file using the write() system call.
    // TODO: Use the length of 'content' as the size to write.
    // TODO: Check if write() failed (bytes_written == -1). If so, print an error using perror, close the file, and return -1.

    // TODO: Print a success message with the number of bytes written and the filename.

    // TODO: Close the file using close(fd).
    // TODO: Check if close() failed. If so, print an error using perror and return -1.

    // TODO: Print a message that the file was closed successfully.
    return 0;
}

int read_file_contents(const char *filename) {
    // TODO: Declare an integer 'fd' for the file descriptor.
    // TODO: Create a buffer array of size 1024 to store the file data.
    // TODO: Declare a variable 'bytes_read' of type ssize_t to store how many bytes are read.

    // TODO: Print a message showing which file is being read.

    // TODO: Open the file for reading using the open() system call.
    // TODO: Use the O_RDONLY flag.
    // TODO: Check if open() failed (fd == -1). If so, print an error using perror and return -1.

    // TODO: Print the file descriptor value.
    // TODO: Print a header for the file contents.

    // TODO: Read the file contents using the read() system call in a loop.
    // TODO: Use sizeof(buffer) - 1 for the buffer size.
    // TODO: Null-terminate the buffer after each read.
    // TODO: Print the contents of the buffer.
    // TODO: Continue reading until read() returns 0.

    // TODO: Check if read() failed (bytes_read == -1). If so, print an error using perror, close the file, and return -1.

    // TODO: Print a footer for the end of the file.

    // TODO: Close the file using close(fd).
    // TODO: Check if close() failed. If so, print an error using perror and return -1.

    // TODO: Print a message that the file was closed successfully.
    return 0;
}
```

**file_operations.h (PROVIDED)**  
This header file contains function prototypes for the file operations implemented in `file_operations.c`. It allows you
to use these functions in `main.c` and ensures proper modularity and code organization. No changes are necessary for
this file.

```c++
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

int create_and_write_file(const char* filename, const char* content);
int read_file_contents(const char* filename);

#endif
```

#### Project Setup

1. **Fork this repository**
    * Visit https://github.com/stjohns-edu/CUS1163-lab01
    * Click the "Fork" button in the top-right corner of the page
    * Wait for the repository to be forked to your GitHub account

2. **Clone your forked repository**
   ```bash
   git clone https://github.com/YOUR-USERNAME/cus1168-lab01
   cd cus1168-lab01
   ```

3. **Complete the TODO sections in `file_operations.c` as instructed.**

#### How to Run the Program

1. **Compile the program:**
   ```bash
   gcc -o lab1 main.c file_operations.c
   ```

2. **Run the executable:**
   ```bash
   ./lab1
   ```

3. **Test the program:**
    - Option 1: Create a file, enter a filename and content.
    - Option 2: Read file contents, enter the filename to verify.
    - Option 3: Exit.

#### Expected Output

```
Linux File Operations Lab
This program demonstrates file operations using system calls

=== Linux File Operations Lab ===
1. Create and write to file
2. Read file contents
3. Exit
Choose an option (1-3): 1
Enter filename to create: myfile.txt
Enter content to write: Hello from system calls!
Creating file: myfile.txt
Content to write: Hello from system calls!
File descriptor: 3
Successfully wrote 24 bytes to 'myfile.txt'
File closed successfully
SUCCESS: File 'myfile.txt' created and written successfully!

=== Linux File Operations Lab ===
1. Create and write to file
2. Read file contents
3. Exit
Choose an option (1-3): 2
Enter filename to read: myfile.txt
Reading file: myfile.txt
File descriptor: 3

--- Contents of 'myfile.txt' ---
Hello from system calls!
--- End of file ---
File closed successfully
SUCCESS: File 'myfile.txt' read successfully!

=== Linux File Operations Lab ===
1. Create and write to file
2. Read file contents
3. Exit
Choose an option (1-3): 3
Exiting program. Goodbye!
```

#### Implementation Hints

- **open() for writing**:  
  `open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);`  
  (Creates a file if it doesn't exist, opens for writing, truncates to zero length, sets permissions.)

- **open() for reading**:  
  `open(filename, O_RDONLY);`  
  (Opens an existing file for reading only.)

- **write()**:  
  `write(fd, content, strlen(content));`  
  (Writes the content string to the file.)

- **read()**:  
  `read(fd, buffer, sizeof(buffer) - 1);`  
  (Reads file contents into the buffer, leaving space for a null terminator.)

#### Troubleshooting

- Make sure you have write permissions in your working directory.
- Confirm the file name and path while testing file reading/writing.
- Check your code for proper error handling after each system call.
- If compilation fails, verify all include statements and function prototypes.

#### Submission

1. After completing your work, push it to your fork repository:
   ```bash
   git add .
   git commit -m "finished homework"
   git push origin main
   ```

2. Ensure your completed code is committed and includes screenshots of your working program output.