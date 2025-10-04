#include <stdio.h>

int arr[100];

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


}