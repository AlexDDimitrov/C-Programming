#include <stdio.h>

#define SIZE 5
#define  SORT(ARRAY, SIZE, TYPE, COMPARE) { \
    for (int i = 0; i < SIZE; i++) { \
        for (int j = 0; j < SIZE - 1; j++) { \
            if (ARRAY[j] COMPARE ARRAY[j+1]) { \
                SWAP_NUMBERS(ARRAY[j], ARRAY[j+1], TYPE); \
            } \
        } \
    } \
}

#define SWAP_NUMBERS(X, Y, TYPE) { \
    TYPE temp = X; \
    X = Y; \
    Y = temp; \
}

int main() {
    int arr[SIZE] = {6, 2, 9, 1, 5};

    SORT(arr, SIZE, int, >);

    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", arr[i]);
        if (i < SIZE - 1) {
            printf(", ");
        }
    }

    /*SORT(arr, SIZE, int, <);

    printf("\nSorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", arr[i]);
        if (i < SIZE - 1) {
            printf(", ");
        }
    }*/
    return 0;
}