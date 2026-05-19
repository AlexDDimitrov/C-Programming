#include <stdio.h>
// a на степен n + b на степен m//
float stepen(float a, int n);
void main(void)
{
    float a, b, s;
    int n, m;

    scanf("%f", &a);
    scanf("%d", &n);
    scanf("%f", &b);
    scanf("%d", &m);
    s=stepen(a, n) + stepen(b, m);
    printf("%.3f", s);
}


float stepen(float a, int n)
{
    float p=1;
    int i, m;
    if (n<0) m=-n;
    else m=n;
    for (i=1; i<=m; i++)
    {
        p = p*a;
    }
    if (n<0) p=1/p;
    return p;
}