#include <stdio.h>

#define SQUARE(A, B) ((A) + (B)) * ((A) + (B))

int main() {
    int a, b;
    printf("Enter two number A: ");
    scanf("%d", &a);
    printf("Enter two number B: ");
    scanf("%d", &b);
    int result = SQUARE(a, b);
    printf("The square of the sum is: %d\n", result);
    return 0;
}