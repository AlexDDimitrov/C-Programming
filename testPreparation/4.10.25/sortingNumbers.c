#include <stdio.h>

int arr[100];

void sort(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;
            }
        }
    }
}

int sum(int n){
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int res = i * arr[i];
        sum = sum + res;
    }
    return sum;
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

    sort(n);

    for (int i=0; i<n; i++) {
        printf("Num %d = %d\n", i+1, arr[i]);
    }

    int s = sum(n);
    printf("Sum = %d", s);
}