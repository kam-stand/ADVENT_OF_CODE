#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


struct HASHMAP{
    int SIZE;
    int *array;    
 };

typedef struct HASHMAP HASHMAP;

struct HASHMAP *createHashmap(int size){
    HASHMAP *hash_map = (HASHMAP *)malloc(sizeof(HASHMAP));
    hash_map->array = (int *)malloc(sizeof(int)*size);
    return hash_map;
}
struct KEY{
    int KEY;
};

typedef struct KEY KEY;

struct KEY *createKey(int val){
    KEY *key = (KEY *)malloc(sizeof(KEY));
    key->KEY = val;
    return key;
}

int main(int argc, char** argv) {
    char *file_path = "./input.txt";

    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char LINE[256];
    int left_list[1000], right_list[1000];
    int i = 0, j = 0;
    char *token;
    int left = 0;

    while (fgets(LINE, sizeof(LINE), file)) {
        token = strtok(LINE, " ");
        while (token != NULL) {
            if (left == 0) {
                if (i < 1000) {
                    left_list[i] = atoi(token);
                    i++;
                    left = 1;
                }
            } else {
                if (j < 1000) {
                    right_list[j] = atoi(token);
                    j++;
                    left = 0;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    // Sort both lists
    qsort(left_list, i, sizeof(int), compare);
    qsort(right_list, j, sizeof(int), compare);

    // Calculate the absolute differences
    int counter = 0;
    int min_size = (i < j) ? i : j; // Use the smaller size for iteration
    for (int k = 0; k < min_size; k++) {
        counter += abs(left_list[k] - right_list[k]);
    }

    printf("Total difference: %d\n", counter);

    return 0;
}
