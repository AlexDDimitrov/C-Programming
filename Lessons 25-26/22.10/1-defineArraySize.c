#include <stdio.h>

#define ARRAY_SIZE 5

int main() {
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5};

    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d", arr[i]);
        if (i < ARRAY_SIZE - 1) {
            printf(", ");
        }
    }
    return 0;
}