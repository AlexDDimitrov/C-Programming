#include <stdio.h>

int main(){
    int n = 0;
    do {
        printf("Enter n: ");
        scanf("%d", &n);
    } while(n<0);

    int end = 0;
    int mult = 0;
    int res = 1;

    do {
        int a = n % 10;
        res = res*a;
        if (n/10==0) {
            end = 1;
        }
        n = n/10;
    } while (end != 1);

    mult = res;
    printf("%d", res);
    return 0;
}