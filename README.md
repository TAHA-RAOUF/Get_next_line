# get_next_line - Read a File Line by Line

## Introduction

This repository contains my implementation of `get_next_line`, a function that reads a file descriptor line by line. This project is part of the 42 curriculum and aims to develop an efficient way to handle file input in C.

## Function Prototype
```c
char *get_next_line(int fd);
```

## Features
- Reads a file or standard input line by line.
- Works with any file descriptor.
- Handles multiple file descriptors simultaneously.
- Uses a buffer to optimize performance.
- Returns `NULL` when the end of the file is reached.

## Implementation Details

### How It Works
1. **Reads Data in Chunks:**
   - Uses `read()` to retrieve a specified number of bytes at a time (defined by `BUFFER_SIZE`).
2. **Stores Unprocessed Data:**
   - Keeps leftover data from previous reads in a static variable.
3. **Extracts and Returns a Line:**
   - Finds the newline character (`'\n'`), extracts the full line, and updates the stored buffer.

### Example Usage
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

### Sample Output (for `test.txt`):
```
Hello, world!
This is a test file.
Reading line by line.
```

## How to Compile and Use
1. Clone the repository:
   ```sh
   git clone https://github.com/YOUR_GITHUB_USERNAME/get_next_line.git
   cd get_next_line
   ```
2. Compile your project with `get_next_line.c`:
   ```sh
   gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl_test
   ```
3. Run the program:
   ```sh
   ./gnl_test
   ```

## Project Constraints
- No use of standard library functions (except `read`, `malloc`, and `free`).
- Must work efficiently with different `BUFFER_SIZE` values.
- Should handle multiple file descriptors at the same time.

## Conclusion
This project helped me understand file reading mechanisms, dynamic memory allocation, and efficient buffer management in C. Feel free to fork and improve it!

