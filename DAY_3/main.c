#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file_contents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Initial buffer size
    size_t buffer_size = 1024;
    char *buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    size_t buffer_used = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        // Reallocate buffer if it's full
        if (buffer_used == buffer_size - 1) {
            buffer_size *= 2;
            char *new_buffer = (char *)realloc(buffer, buffer_size);
            if (!new_buffer) {
                perror("Memory reallocation failed");
                free(buffer);
                fclose(file);
                return NULL;
            }
            buffer = new_buffer;
        }

        buffer[buffer_used++] = c;
    }

    // Null-terminate the string
    buffer[buffer_used] = '\0';

    fclose(file);
    return buffer;
}

int main() {
    char *content = read_file_contents("input.txt");
    if (!content) {
        return 1;
    }

    for (int i = 0; i < strlen(content); i++) {
        if (content[i] == '\n') {
            printf("\n");
        } else {
            printf("%c", content[i]);
        }
    }

    free(content);
    return 0;
}