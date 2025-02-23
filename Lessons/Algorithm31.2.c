// n-тото число от редицатан на Фибуначи
#include <stdio.h>

int fib(int n);
int fib_min(int n);
int fib_max(int n);

void main()
{
    int n;
    do {
        printf("Enter n = ");
        scanf("%d", &n);
    } while(n<1);
    printf("\nfib(%d)=%d", n, fib(n));
    printf("\nfib_min(%d)=%d", n, fib_min(n));
    printf("\nfib_max(%d)=%d", n, fib_max(n));
}
int fib(int n)
{
    int i, a=1, b=1, c=1;
    for (i=3; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int fib_min(int n) {
    int num1=1;
    int num2=1;
    int num3=1;
    while(num3<n)
    {
        num3=num1+num2;
        num1=num2;
        num2=num3;
    }
    return num3;
}
int fib_max(int n) {
    int i, a=1, b=1, c=1;
    for (i=3; i<=n+1; i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}