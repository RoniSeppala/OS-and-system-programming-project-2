#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[]) {

    // inital argument check
    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        return 1;
    }

    // variable intialization for run-length encoding
    uint32_t count = 0;
    int prev = EOF;
    int c;

    for (int i = 1; i < argc; i++) { // loop through each file
        // open the file in binary read mode
        FILE *fp = fopen(argv[i], "rb"); //
        if (!fp) {
            printf("my-zip: cannot open file\n"); // error handling for file opening
            return 1; 
        }

        while ((c = fgetc(fp)) != EOF) { // read each character until EOF
            if (prev == EOF) { // first character
                prev  = c;
                count = 1;
            } else if (c == prev) { // if the character is the same as the previous one
                count++;
            } else { // if the character is different write the count and character to stdout
                fwrite(&count, sizeof(count), 1, stdout);
                fputc(prev,     stdout);
                prev  = c;
                count = 1;
            }
        }

        fclose(fp); // close the file after reading
    }

    if (prev != EOF) { // if there is a character left to write after the loop
        fwrite(&count, sizeof(count), 1, stdout);
        fputc(prev, stdout);
    }
    
    return 0;
}