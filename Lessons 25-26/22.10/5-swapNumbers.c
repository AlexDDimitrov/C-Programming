#include <stdio.h>

#define SWAP_NUMBERS(x, y) { \
    int temp = x; \
    x = y; \
    y = temp; \
}

int main() {
    int num1 = 10;
    int num2 = 20;

    SWAP_NUMBERS(num1, num2);

    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}