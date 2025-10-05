#include <stdio.h>

void turnBinary(int n){
    int arr[100];
    int max = 0;

    for (int i = 0; n > 0; i++) {
        arr[i] = n % 2;
        n /= 2;
        max = i;
    }

    long binaryNumber = 0;
    for (int i = max; i >= 0; i--) {
        binaryNumber = binaryNumber * 10 + arr[i];
    }

    printf("%ld\n", binaryNumber);
}

int main() {   
    int n = 0;
    
    do {
        printf("Enter n: ");
        scanf("%d", &n);
    } while(n < 0);

    turnBinary(n);
    
    return 0;
}
