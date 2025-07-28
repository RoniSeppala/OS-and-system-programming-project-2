#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        return 0; // No arguments provided, do nothing
    }

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) { //check if file opened successfully
            printf("my-cat: cannot open file\n");
            return 1;
        }

        // Read and print the contents of the file
        int ch;
        int last = -1;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
            last = ch;
        }
        fclose(file);
        /*
        if (last != '\n' && last != -1) {  // if the last character is not a newline, print one
            putchar('\n');
        }
        */
    }

    return 0;
}