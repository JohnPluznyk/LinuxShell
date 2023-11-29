#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("my_grep: searchterm [file ...]\n");
        return 1;
    }

    char *search_term = argv[1];

    for (int i = 2; i < argc; i++) {
        char *filename = argv[i];
        FILE *file = fopen(filename, "r");

        if (file == NULL) {
            printf("my_grep: cannot open %s\n", filename);
            return 1;
        }

        char *line = NULL;
        size_t line_size = 0;

        while (getline(&line, &line_size, file) != -1) {
            if (search_term[0] == '\0' || strstr(line, search_term) != NULL) {
                printf("%s", line);
            }
        }

        free(line);
        fclose(file);
    }

    return 0;
}