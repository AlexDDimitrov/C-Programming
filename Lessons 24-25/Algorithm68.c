#include <stdio.h>
#define MAX 10

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (target > arr[mid]) {
        return binarySearch(arr, mid + 1, right, target);
    } else {
        return binarySearch(arr, left, mid - 1, target);
    }
}

int main() {
    int a[MAX];
    int i, n, s;
    int min, mini, k;
    int result;

    do {
        printf("Enter the number of elements in the array (max %d): ", MAX);
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Enter the number to find: ");
    scanf("%d", &s);

    for (i = 0; i < n - 1; i++) {
        min = a[i];
        mini = i;
        for (k = i + 1; k < n; k++) {
            if (a[k] < min) {
                min = a[k];
                mini = k;
            }
        }
        a[mini] = a[i];
        a[i] = min;
    }

    result = binarySearch(a, 0, n - 1, s);

    if (result != -1) {
        printf("Element %d found in the sorted array.\n", result);
    } else {
        printf("Element %d not found in the array.\n", s);
    }

    return 0;
}