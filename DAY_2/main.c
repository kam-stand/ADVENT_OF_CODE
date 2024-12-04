#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int find_length(char *line) {
    char *temp = strdup(line);
    int length = 0;
    char *token = strtok(temp, " ");
    while (token != NULL) {
        length++;
        token = strtok(NULL, " ");
    }
    free(temp); // Free the temporary copy
    return length;
}

int *createArray(char *line, int length) {
    char *temp = strdup(line);
    int *Array = malloc(sizeof(int) * length);
    int i = 0;
    char *token = strtok(temp, " ");
    while (token != NULL) {
        Array[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(temp); // Free the temporary copy
    return Array;
}

void printArray(int *Array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", Array[i]);
    }
}

int validDiff(int *array, int length) {
    for (int i = 0; i < length - 1; i++) { // Prevent out-of-bounds access
        int diff = abs(array[i] - array[i + 1]);
        if (diff < 1 || diff > 3) { // Ensure valid difference is between 1 and 3
            return 0;
        }
    }
    return 1;
}

int isIncreasing(int *array, int length) {
    for (int i = 1; i < length; i++) {
        if (array[i] <= array[i - 1]) { // Ensure strictly increasing
            return 0;
        }
    }
    return 1;
}

int isDecreasing(int *array, int length) {
    for (int i = 1; i < length; i++) {
        if (array[i] >= array[i - 1]) { // Ensure strictly decreasing
            return 0;
        }
    }
    return 1;
}



int main(void) {
    FILE *file = fopen("./input.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char line[1024];
    int total = 0;
    while (fgets(line, sizeof(line), file)) {
        printf("The line is: %s\n", line);

        int length = find_length(line);
        int *Array = createArray(line, length);
        printf("The array is increasing?: %d\n", isIncreasing(Array, length));
        printf("The array is decreasing?: %d\n", isDecreasing(Array, length));
        printf("The array is valid %d\n", validDiff(Array, length));
        int increase = isIncreasing(Array,  length);
        int decreasing = isDecreasing(Array,  length);
        int valid = validDiff(Array, length);
        if(increase == 1 && valid == 1){
            total +=1;
        }
        if(decreasing == 1 && valid == 1){
            total +=1;
        }

        free(Array); // Free the dynamically allocated array
    }
    printf("The total is %d\n", total);

    fclose(file);
    return 0;
}
