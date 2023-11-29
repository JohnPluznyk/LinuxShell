#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
    Current bugs in program:
*/

int main(int argc, char *argv[]) {

    int baseCase = 1;
    int count_lines = 0;
    int count_words = 0;
    int count_chars = 0;
    int option_count = 0; // Track the number of options used

    if (argc < 2) {
        printf("my_wc: [option ...] [file ...]\n");
        return 1;
    }

    // Check for options
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0 && option_count < 3) {
            count_lines = 1;
            baseCase = 0;
            option_count++;
        } else if (strcmp(argv[i], "-w") == 0 && option_count < 3) {
            count_words = 1;
            baseCase = 0;
            option_count++;
        } else if (strcmp(argv[i], "-c") == 0 && option_count < 3) {
            count_chars = 1;
            baseCase = 0;
            option_count++;
        } else {
            break; // Stop processing options if a file is encountered
        }
    }

    if(baseCase == 1){
        count_lines = 1;
        count_words = 1;
        count_chars = 1;
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {  //lol i have no idea why this is here
            continue; // Skip options
        }

        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            fprintf(stderr, "my_wc: cannot open file\n");
            return 1;
        }

        int line_count = 0;
        int word_count = 0;
        int char_count = 0;
        int in_word = 0;
        int c;

        while ((c = fgetc(file)) != EOF) {
            char_count++;
            if (count_lines && c == '\n') {
                line_count++;
            }
            if (count_words && isspace(c)) {
                in_word = 0;
            } else if (count_words && !in_word) {
                in_word = 1;
                word_count++;
            }
        }

        fclose(file);

        if (count_lines) {
            printf("%d ", line_count);
        }
        if (count_words) {
            printf("%d ", word_count);
        }
        if (count_chars) {
            printf("%d ", char_count);
        }

        printf("%s\n", argv[i]);
    }

    return 0;
}