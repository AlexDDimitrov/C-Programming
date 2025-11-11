#include <stdio.h>
#include <stddef.h>

void os_sort(int *arr, int n) {
#if defined(_WIN32)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp;
            }
        }
    }
#elif defined(__linux__)
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) mini = j;
        }
        if (mini != i) {
            int temp = arr[i]; 
            arr[i] = arr[mini]; 
            arr[mini] = temp;
        }
    }
#elif defined(__APPLE__)
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
#else
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
#endif
}

void print_array(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i) putchar(' ');
        printf("%d", arr[i]);
    }
    putchar('\n');
}

int main(void) {
    int a[] = {4, 2, 9, 1, 5, 6};
    int n = 6;

    printf("Before: ");
    print_array(a, n);

    os_sort(a, n);

    printf("After:  ");
    print_array(a, n);

    return 0;
}