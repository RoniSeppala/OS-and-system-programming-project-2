#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void my_grep(const char *search_term, FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, file)) != -1) {
        if (strstr(line, search_term) != NULL) {
            fputs(line, stdout);
            // if the line we read didn’t include a '\n', add one
            if (nread > 0 && line[nread - 1] != '\n') {
                putchar('\n');
            }
        }
    }

    free(line);
    if (file != stdin) {
        fclose(file); // Close the file if it is not standard input
    }
    
}

int main(int argc, char *argv[]) {
    if (argc < 2) { // Check if correct number of arguments is provided
        printf("my-grep: searchterm [file ...]\n");
        return 1;
    }

    if (argc == 2) {
        // If only search term is provided, read from standard input
        my_grep(argv[1], stdin);
    } else {
        // If file names are provided, read each file
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) { // Check if file opened successfully
                printf("my-grep: cannot open file");
                return 1;
            }
            my_grep(argv[1], file);
        }
    }
    
    return 0;
}