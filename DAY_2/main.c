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

int isIncreasing(int *array, int length) {
   // only checking if its all increasing
   int j = 0;
   for(int i =1; i<length; i++){
    if((array[j] < array[i])){
        j++;
    }else {
        return 0;
    }
   }
   return 1;
}

int isDecreasing(int *array, int length) {
    int j = 0;
   for(int i =1; i<length; i++){
    if((array[j] > array[i])){
        j++;
    }
    else {
        return 0;
    }
   }
    return 1; // Decreasing
}

int validDiff(int *array, int length){
    for(int i = 0; i<length; i++){
        int diff = abs(array[i] - array[i+1]);
        if (diff < 1 || diff > 4) { // Ensure strictly decreasing by at most 3
            return 0; // Not decreasing
        }

    }
    return 1;
}


int main(void) {
    FILE *file = fopen("./test.txt", "r");
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

      

        free(Array); // Free the dynamically allocated array
    }
    printf("The total is %d\n", total);

    fclose(file);
    return 0;
}
