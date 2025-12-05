#include <stdio.h>
#include "quadraticroots.h"

int main() {
    long double a;
    long double b;
    long double c;

    printf("a: ");
    scanf("%Lf", &a);
    printf("b: ");
    scanf("%Lf", &b);
    printf("c: ");
    scanf("%Lf", &c);

    QuadraticRootResult result = findRoots(a, b, c);

    if (result.norealroots) {
        printf("No real roots exist.\n");
    } else if (result.x1 == result.x2) {
        printf("One real root: x = %.2Lf\n", result.x1);
    } else {
        printf("Two real roots: x1 = %.2Lf, x2 = %.2Lf\n", result.x1, result.x2);
    }

    return 0;
}