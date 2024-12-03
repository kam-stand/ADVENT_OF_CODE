#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
1. read each line in the file
2. from each line take the numbers and convert to int array
3. check if int array is increasing or decreasing given the absolute different is at most 3

*/

int find_length(char *line){
    // copy the line
    char *temp = strdup(line);
    int length = 0;
    char *token = strtok(temp, " ");
        while (token != NULL) {
            length +=1;
            token = strtok(NULL, " ");
    }
    return length; 
}
int *createArray(char *line, int length){
    // initialize array
    char *temp = strdup(line);
    int *Array = malloc(sizeof(int) * length);
    int i =0;
    for(int i = 0; i< length; i++){
        char *token  = strtok(temp, " ");
        while (token != NULL) {
            Array[i] = atoi(token);
            i++;
            token = strtok(NULL, " ");
        }
    }
    return  Array;
}

void printArray(int *Array, int length){
    for(int i = 0; i <length; i++){
        printf("%d\n", Array[i]);
    }
}
// create isIncreasing and isDecreasing function
// if Either or check if all differences is valid

int main(void) {
    FILE *file = fopen("./test.txt", "r");
    char line[1024];
    // 1. read each line in the file
    while (fgets(line, sizeof(line), file)) {
        printf("the line is: %s\n", line);
        //printf("the length is: %d\n", find_length(line));
        int *Array = createArray(line, find_length(line));
        printArray(Array, find_length(line));
        // check for either increasing or decreasing
        // if either or check if its valid differences
    }

    return 0;
}