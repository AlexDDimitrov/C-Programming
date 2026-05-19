#include <stdio.h>
#define MAX 10
//First non-negative number in the array and the sum of all numbers before it.

int sum = 0;
int find_first_non_negative(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            return arr[i];
        }
        sum += arr[i];
    }
    return -1;
}

int main() {
    int n;
    int A[MAX];

    do {
        printf("Enter the number of elements (max %d): ", MAX);
        scanf("%d", &n);
        if (n <= 0 || n > MAX) {
            printf("Invalid input! Please enter a number between 1 and %d.\n", MAX);
        }
    } while (n <= 0 || n > MAX);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    int result = find_first_non_negative(A, n);
    if (result == -1) {
        printf("No non-negative number found in the array.\n");
    } else {
        printf("The first non-negative number in the array is: %d\n", result);
        printf("Sum of numbers before the first non-negative: %d\n", sum);
    }

    return 0;
}