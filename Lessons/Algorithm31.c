#include <stdio.h>

void main() 
{
    double n, s, a, b, i=1;

    do{
        printf("n = ");
        scanf("%lf", &n);
    } while (n < 0);
    
    a = 0;
    b = 1;

    do {
        s = b + a;
        a = b;
        b = s;
        i++;
    } while (i < n);

    printf("s = %.0lf", s);
}