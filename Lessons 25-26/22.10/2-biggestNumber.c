#include <stdio.h>

#define BIGGEST_NUMBER a > b ? a : b

int main() {
    int a = 10;
    int b = 20;
    int c = BIGGEST_NUMBER;
    printf("The biggest number between %d and %d is %d\n", a, b, c);
    return 0;
}