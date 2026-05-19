#include <stdio.h>
#define MAX 10
#define MAXC 20
//Merge two arrays into a third array.

void sort(int arr[], int k) {
    int i, j, key;
    for (i = 1; i < k; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int A[], int a, int B[], int b, int C[]) {
    int i = 0, j = 0, k = 0;
    while (i < a && j < b) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = A[j++];
        }
    }
    while (i < a) {
        C[k++] = A[i++];
    }
    while (j < b) {
        C[k++] = B[j++];
    }
}

int main() {
    int A[MAX], B[MAX], C[MAXC];
    int a, b;

    do {
        printf("Enter the number of elements for array A (max %d): ", MAX);
        scanf("%d", &a);
        if (a <= 0 || a > MAX) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX);
        }
    } while (a <= 0 || a > MAX);

    printf("Enter elements for array A:\n");
    for (int i = 0; i < a; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    do {
        printf("Enter the number of elements for array B (max %d): ", MAX);
        scanf("%d", &b);
        if (b <= 0 || b > MAX) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX);
        }
    } while (b <= 0 || b > MAX);

    printf("Enter elements for array B:\n");
    for (int i = 0; i < b; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &B[i]);
    }

    sort(A, a);
    sort(B, b);
    merge(A, a, B, b, C);

    printf("Sorted array A: ");
    for (int i = 0; i < a; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Sorted array B: ");
    for (int i = 0; i < b; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    printf("Merged array C: ");
    for (int i = 0; i < a + b; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}