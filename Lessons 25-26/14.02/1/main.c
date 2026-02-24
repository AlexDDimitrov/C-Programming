#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeline(char *str) { 
    char *p = strchr(str, '\n'); 
    if (p != NULL) *p = '\0'; 
}

void swap(void *a, void *b) {
    int *n1 = (int *)a; 
    int *n2 = (int *)b;

    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int compareasc(const void *a, const void *b) { 
    int x = *(const int *)a; 
    int y = *(const int *)b; 
    return x>y? 1 : (x<y ? -1 : 0);
}

int comparedesc(const void *a, const void *b) { 
    int x = *(const int *)a; 
    int y = *(const int *)b; 
    return x<y? 1 : (x>y ? -1 : 0);
}

void bubblesort(void *arr, int n, int (*compare)(const void *, const void *), void (*swapelements)(void *, void *)) {
    int *a = (int *)arr;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(&a[j], &a[j + 1]) > 0) {
                swapelements(&a[j], &a[j + 1]);
            }
        }
    }
}

int main() {
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    
    double *pa = &a;
    double *pb = &b;

    printf("Addres at a: %p, value: %.2f\n", pa, *pa); 
    printf("Addres at b: %p, value: %.2f\n", pb, *pb);

    char buffer[50]; 
    getchar();
    printf("Enter a string: "); 
    fgets(buffer, sizeof(buffer), stdin); 
    removeline(buffer); 
    printf("After removing newline: '%s'\n", buffer);

    int x = 10, y = 20;

    swap(&x, &y);
    printf("After swapping x and y:\n");
    printf("x: %d, y: %d\n", x, y);

    int arr[] = {5, 1, 9, 3, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    bubblesort(arr, n, compareasc, swap);
    printf("\nAscending sort: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    int arr2[] = {5, 1, 9, 3, 7};
    bubblesort(arr2, n, comparedesc, swap);
    printf("\nDescending sort: ");
    for (int i = 0; i < n; i++) printf("%d ", arr2[i]);
    
    printf("\n");
    return 0;
}
    