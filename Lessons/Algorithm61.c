#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10

void bubble_sort(int A[], int n);
void straight_sort(int A[], int n);
void insertion_sort(int A[], int n);

int main(void) {
    int choice = 1, exit = 0;
    char key;
    int arr[MAX], n = 0;

    do {
        system("cls");
        printf(" Menu\n");
        if (choice == 1) printf(">");
        else printf(" ");
        printf("1. Enter variables\n");
        if (choice == 2) printf(">");
        else printf(" ");
        printf("2. Bubble sort\n");
        if (choice == 3) printf(">");
        else printf(" ");
        printf("3. Straight sort\n");
        if (choice == 4) printf(">");
        else printf(" ");
        printf("4. Straight insertion sort\n");
        if (choice == 5) printf(">");
        else printf(" ");
        printf("5. Quit\n");

        key = getch();
        if (key == -32 || key == 224) {
            key = getch();
            if (key == 72) choice--;
            if (key == 80) choice++;
        }
        if (choice > 5) choice = 1;
        if (choice < 1) choice = 5;

        if (key == '\r') {
            switch (choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                while (n <= 0 || n > MAX) {
                    printf("Invalid number! Enter again: ");
                    scanf("%d", &n);
                }
                for (int i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                printf("Elements entered!\n");
                break;
            case 2:
                bubble_sort(arr, n);
                break;
            case 3:
                straight_sort(arr, n);
                break;
            case 4:
                insertion_sort(arr, n);
                break;
            case 5:
                printf("Exiting...\n");
                exit = 1;
                break;
            }
            if (choice != 5) {
                printf("Press any key to continue...");
                getch();
            }
        }
    } while (!exit);

    return 0;
}

void bubble_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    printf("Array after Bubble Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
}

void straight_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min_idx]) min_idx = j;
        }
        int temp = A[i];
        A[i] = A[min_idx];
        A[min_idx] = temp;
    }
    printf("Array after Straight Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
}

void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
    printf("Array after Insertion Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
}
