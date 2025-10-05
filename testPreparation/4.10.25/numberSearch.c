#include <stdio.h>

int arr[100];

int binarySearch(int a, int n) {
    int ind = -1;
    int l = 0;
    int h = n-1;
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (arr[m] == a) {
            ind = m;
            return ind;
        }
        if (arr[m] < a)
            l = m + 1;
        else
            h = m - 1;
    }

    return ind;
}

int main() {
    int n = 0;
    do {
        printf("Enter n: ");
        scanf("%d", &n);
    } while(n<0 || n>100);

    for (int i=0; i<n; i++) {
        printf("Enter num %d: ", i+1);
        scanf("%d", &arr[i]); 
    }

    int a = 0;
    printf("Enter searched number: ");
    scanf("%d", &a);
    
    int findNum = binarySearch(a, n);

    printf("%d", findNum);
    return 0;
}