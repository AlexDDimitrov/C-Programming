#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUMNS 4

int strlenfinder(const char *s) {
    int count = 0;
    while (*s != '\0') {
        s++;
        count++;
    }
    return count;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int *p1 = arr + j;
            int *p2 = arr + j + 1;

            if (*p1 > *p2) {
                swap(p1, p2);
            }
        }
    }
}

void strhalf(char *str, char **halfstr) {
    int len = strlenfinder(str);
    *halfstr = str + (len / 2);
}

void ArrayOut(int (* arr)[COLUMNS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter string: ");
    char str[100];
    fgets(str, sizeof(str), stdin);
    char *p = strchr(str, '\n');
    if (p != NULL) *p = '\0';

    int len = strlenfinder(str);
    printf("Length of the string: %d\n", len);

    char *ptr = NULL;
    strhalf(str, &ptr);
    printf("Half of the string: %s\n", ptr);

    int array[3][COLUMNS] = { 
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12} 
    }; 
    ArrayOut(array, sizeof(array) / sizeof(array[0]));
}