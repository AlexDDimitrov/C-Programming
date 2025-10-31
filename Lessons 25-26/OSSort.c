#include <stdio.h>
#include <stddef.h>

void os_sort(int *arr, int n) {
#if defined(_WIN32)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < n - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
            }
        }
    }
#elif defined(__linux__)
    for (int i = 0; i < n; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            int t = arr[i]; arr[i] = arr[min_idx]; arr[min_idx] = t;
        }
    }
#elif defined(__APPLE__)
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
#else
    for (int i = 0; i < n / 2; ++i) {
        int t = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = t;
    }
#endif
}

void print_array(const int *arr, int n) {
    for (int i = 0; i < n; ++i) {
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