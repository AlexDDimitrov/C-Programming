#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compareasc(int a, int b) {
    return a>b ? 1 : (a==b ? 0 : -1);
}

int comparedesc(int a, int b) {
    return a<b ? 1 : (a==b ? 0 : -1);
}

int * sort(int arr[], int size, int (*ptr)(int, int)) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if(ptr(arr[j], arr[j+1]) == 1) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    return arr;
}

int main(void) {
    int size;
    printf("Enter number: ");
    scanf("%d", &size);
    int* arr = malloc(size * sizeof(int));
    if(arr == NULL) {
        free(arr);
        printf("Error");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int* arr2;
    arr2 = sort(arr, size, compareasc);

    for (int i = 0; i < size; i++) {
        printf("Value of %d is %d\n", i+1, arr2[i]);
    }

    arr2 = sort(arr, size, comparedesc);

    for (int i = 0; i < size; i++) {
        printf("Value of %d is %d\n", i+1, arr2[i]);
    }
    free(arr);
}   