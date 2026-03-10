#include <stdio.h>
#include <stdlib.h>

double pow2(double a) {
    return a * a;
}

double pow4(double a) {
    return ((a * a) * (a * a));
}

double* map(double ptrArr[], int size, double  (*ptr)(double)) {
    double* newArr = malloc(size * sizeof(double));

    if(newArr == NULL) {
        printf("Error");
        exit(1);
    }

    for(int i=0;i<size;i++) {
        newArr[i] = ptr(ptrArr[i]);
    }

    return newArr;
}

int main(void) {

    int size;
    printf("Enter number: ");
    scanf("%d", &size);
    getchar();

    double *arr = malloc(size * sizeof(double));
    if(arr == NULL) {
        free(arr);
        printf("Error");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%lf", &arr[i]);
    }

    int choice;
    printf("Enter power of 2 or 4 (0 for ^2 and 1 for ^4): ");
    scanf("%d", &choice);

    double *arr2;

    arr2 = map(arr, size, (choice==1 ? pow4 : pow2));
    for (int i = 0; i < size; i++) {
        printf("Value of %d is %f\n", i+1, arr2[i]);
    }

    free(arr);
    free(arr2);
}