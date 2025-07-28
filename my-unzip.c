#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-unzip: file1 [file2 ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "rb");
        if (fp == NULL) {
            printf("my-unzip: cannot open file\n");
            return 1;
        }

        while (1) {
            uint32_t count;
            unsigned char ch;

            /* read a 4-byte run length; break on EOF */
            if (fread(&count, sizeof(count), 1, fp) != 1) {
                break;
            }

            /* read the single character */
            if (fread(&ch, 1, 1, fp) != 1) {
                /* malformed file: count without a character */
                break;
            }

            /* output the character 'count' times */
            for (uint32_t j = 0; j < count; j++) {
                putchar(ch);
            }
        }

        fclose(fp);
    }

    return 0;
}