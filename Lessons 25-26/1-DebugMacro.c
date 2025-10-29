#include <stdio.h>
#include <stdlib.h>

#define DEBUG

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void devidableBy3(int arr[], int size) {
    int sum = 0;
    printf("Elements devidable by 3: ");
    
    for (int i = 0; i < size; i++) {
        if (arr[i] % 3 == 0) {
            if (arr[i] != 0) {
                printf("%d ", arr[i]);
                sum += arr[i];
            }
        }
    }
    
    printf("\nSum: %d\n", sum);
}

int main() {
    int arr[] = {5, 3, 8, 6, 2, 7, 4, 1, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
#ifdef DEBUG
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nArray printed successfully.\n");
#endif

    sortArray(arr, size);

#ifdef DEBUG
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nArray sorted successfully.\n");
#endif

    devidableBy3(arr, size);

    return 0;
}