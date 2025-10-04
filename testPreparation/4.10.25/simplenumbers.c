#include <stdio.h>

int main() {
    int n = 0;
    do {
        printf("Enter n: ");
        scanf("%d", &n);
    } while(n<0 || n>100);

    int arr[100];

    for (int i=0; i<n; i++) {
        do {
            printf("Enter num %d: ", i+1);
            scanf("%d", &arr[i]);
        } while(arr[i]<1);
    }

    int simp = 0;
    int sum = 0;
    for (int i=0; i<n; i++) {
        int del = 2;
        simp = 0;
        do {
            if (arr[i] == 1) {
                simp = 1;
                break;
            }
            if(arr[i]%del == 0){
                if (arr[i] == del){
                    simp = 0;
                    break;
                } 
                else {
                    simp = 1;
                }
            } else {
                del++;
            }
        } while(arr[i] == del);
        if(simp == 0) {
            sum = sum + arr[i];
        }
    }
    printf ("sum = %d", sum);
    return 0;
}