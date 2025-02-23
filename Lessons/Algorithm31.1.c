#include <stdio.h>
//fibonacci
void main() 
{
    double n, a = 0, b = 1, s = 0;

    do {
        printf("Enter a positive number: ");
        scanf("%lf", &n);
    } while (n < 0);

    while (s < n) {
        s = a + b;
        a = b;
        b = s;
    }
    printf("The closest larger Fibonacci number to %.0lf is %.0lf\n", n, s);
}
