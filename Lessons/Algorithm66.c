#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int search(int a[], int n, int s) ;

int main() {
    int a[MAX];
    int i, n, s, found = 0;
    int min, mini, k;
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

    found = search(a, n, s);

    if (found) {
        printf("Element %d found in the array.\n", s);
    } else {
        printf("Element %d not found in the array.\n", s);
    }

    return 0;
}

int search(int a[], int n, int s) {
    int i;
    for (i = 0; i < n; i++) {
        if(a[i] < s) {
            return 0; 
        }
        if (a[i] == s) {
            return 1; 
        }
    }
    return 0; 
}