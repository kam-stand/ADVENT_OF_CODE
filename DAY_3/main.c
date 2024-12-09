#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_buffer(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        // Handle file open error
        perror("Failed to open file");
        return -1; // Indicate error
    }

    int ch;
    int curr = 0;
    int max = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (ch != '\n') {
            curr++;
        } else {
            if (curr > max) {
                max = curr;
            }
            curr = 0; // Reset current line length
        }
    }

    // Handle the last line if it doesn't end with a newline
    if (curr > max) {
        max = curr;
    }

    fclose(file); // Close the file to release resources
    return max;
}

int main() {
    int size = max_buffer("./test.txt");
    FILE *file = fopen("./test.txt", "r");
    char line[size];
    while (fgets(line, sizeof(line), file)){
        int length = strlen(line);
        for(int i = 0;  i<length-2; i++){
            if (line[i] == 'm' && line[i+1] == 'u' && line[i+2] == 'l') {
                if (line[i+3] == '(') {
                    break;
                }
                

            }
        }
    }
    return 0;
}