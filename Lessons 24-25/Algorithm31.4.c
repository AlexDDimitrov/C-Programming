#include <stdio.h>

int fib1(int n);
int fib2(int n);

int count=0;

void main()
{
    int n;
    do {
        printf("Enter n = ");
        scanf("%d", &n);
    } while(n<1);
    printf("\nfib(%d)=%d", n, fib1(n));
    
    printf("\nfib(%d)=%d", n, fib2(n));
    printf("\nfib2 was called %d times", count);
}

int fib1(int n)
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

int fib2(int n)
{
    count++;
    if(n<3) return 1;
    else return fib2(n-1) + fib2(n-2);
}