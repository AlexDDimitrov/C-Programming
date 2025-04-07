#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30000

void bubble_sort(int arr[], int size) {
    int i, j, temp, sorted;
    for (i = 0; i < size; i++) {
        sorted = 1;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 0;
            }
        }
        if (sorted) break;
    }
}

void straight_sort(int arr[], int size) {
    int i, j, min, min_idx, temp;
    for (i = 0; i < size - 1; i++) {
        min = arr[i];
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void straight_insertion_sort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void random() {
    unsigned int i;
    int A[MAX], B[MAX], C[MAX];
    clock_t start, end;
    double bubble_time, straight_time, insertion_time;
    printf("\n--- Sorting ---\n");

    printf("Initializing arrays A, B, and C with random values...\n");
    for (i = 0; i < MAX; i++) {
        int n = rand() % 1000000001;
        A[i] = n;
        B[i] = n;
        C[i] = n;
    }

    printf("Sorting array A using Bubble Sort...\n");
    start = clock();
    bubble_sort(A, MAX);
    end = clock();
    bubble_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort completed in %f seconds.\n", bubble_time);

    printf("Sorting array B using Straight Sort...\n");
    start = clock();
    straight_sort(B, MAX);
    end = clock();
    straight_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Straight Sort completed in %f seconds.\n", straight_time);

    printf("Sorting array C using Straight Insertion Sort...\n");
    start = clock();
    straight_insertion_sort(C, MAX);
    end = clock();
    insertion_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Straight Insertion Sort completed in %f seconds.\n", insertion_time);

    printf("\n--- Sorting Times ---\n");
    printf("Bubble Sort time: %f seconds\n", bubble_time);
    printf("Straight Sort time: %f seconds\n", straight_time);
    printf("Straight Insertion Sort time: %f seconds\n", insertion_time);

    printf("\n--- Fastest Sorting Method ---\n");
    if (bubble_time < straight_time && bubble_time < insertion_time) {
        printf("Bubble Sort was the fastest.\n");
    } else if (straight_time < bubble_time && straight_time < insertion_time) {
        printf("Straight Sort was the fastest.\n");
    } else {
        printf("Straight Insertion Sort was the fastest.\n");
    }

}

void from1ToMax()
{
    unsigned int i;
    int A[MAX], B[MAX], C[MAX];
    clock_t start, end;
    double bubble_time, straight_time, insertion_time;
    printf("\n--- Sorting ---\n");

    printf("Initializing arrays A, B, and C with values from 1 to 1000000000...\n");
    for (i = 0; i < MAX; i++) {
        A[i] = i + 1;
        B[i] = i + 1;
        C[i] = i + 1;
    }

    printf("Sorting array A using Bubble Sort...\n");
    start = clock();
    bubble_sort(A, MAX);
    end = clock();
    bubble_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort completed in %f seconds.\n", bubble_time);

    printf("Sorting array B using Straight Sort...\n");
    start = clock();
    straight_sort(B, MAX);
    end = clock();
    straight_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Straight Sort completed in %f seconds.\n", straight_time);

    printf("Sorting array C using Straight Insertion Sort...\n");
    start = clock();
    straight_insertion_sort(C, MAX);
    end = clock();
    insertion_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Straight Insertion Sort completed in %f seconds.\n", insertion_time);

    printf("\n--- Sorting Times ---\n");
    printf("Bubble Sort time: %f seconds\n", bubble_time);
    printf("Straight Sort time: %f seconds\n", straight_time);
    printf("Straight Insertion Sort time: %f seconds\n", insertion_time);

    printf("\n--- Fastest Sorting Method ---\n");
    if (bubble_time < straight_time && bubble_time < insertion_time) {
        printf("Bubble Sort was the fastest.\n");
    } else if (straight_time < bubble_time && straight_time < insertion_time) {
        printf("Straight Sort was the fastest.\n");
    } else {
        printf("Straight Insertion Sort was the fastest.\n");
    }
}

void fromMAXTo1()
{
    unsigned int i;
    int A[MAX], B[MAX], C[MAX];
    clock_t start, end;
    double bubble_time, straight_time, insertion_time;
    printf("\n--- Sorting ---\n");

    printf("Initializing arrays A, B, and C with values from 1000000000 to 1...\n");
    for (i = 0; i < MAX; i++) {
        A[i] = MAX - i;
        B[i] = MAX - i;
        C[i] = MAX - i;
    }

    printf("Sorting array A using Bubble Sort...\n");
    start = clock();
    bubble_sort(A, MAX);
    end = clock();
    bubble_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort completed in %f seconds.\n", bubble_time);

    printf("Sorting array B using Straight Sort...\n");
    start = clock();
    straight_sort(B, MAX);
    end = clock();
    straight_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Straight Sort completed in %f seconds.\n", straight_time);

    printf("Sorting array C using Straight Insertion Sort...\n");
    start = clock();
    straight_insertion_sort(C, MAX);
    end = clock();
    insertion_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Straight Insertion Sort completed in %f seconds.\n", insertion_time);

    printf("\n--- Sorting Times ---\n");
    printf("Bubble Sort time: %f seconds\n", bubble_time);
    printf("Straight Sort time: %f seconds\n", straight_time);
    printf("Straight Insertion Sort time: %f seconds\n", insertion_time);

    printf("\n--- Fastest Sorting Method ---\n");
    if (bubble_time < straight_time && bubble_time < insertion_time) {
        printf("Bubble Sort was the fastest.\n");
    } else if (straight_time < bubble_time && straight_time < insertion_time) {
        printf("Straight Sort was the fastest.\n");
    } else {
        printf("Straight Insertion Sort was the fastest.\n");
    }
}


int main() {
    do{
        printf("\n--- Pick one of the options below ---\n");
        printf("Sorting algorithms performance test\n");
        printf("1. Random values\n");
        printf("2. Values from 1 to 1000000000\n");
        printf("3. Values from 1000000000 to 1\n");
        printf("Please select an option (1-3): ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                random();
                break;
            case 2:
                from1ToMax();
                break;
            case 3:
                fromMAXTo1();
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}
