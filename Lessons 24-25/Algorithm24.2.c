#include <stdio.h>
// a на степен n//
float stepen1(float a, int n);
float stepen2(float a, int n);
void main(void)
{
    float a, b, s;
    int n, m;

    printf("Enter a");
    scanf("%f", &a);
    scanf("%d", &n);
    s=stepen1(a, n);
    printf("%.3f", s);
    s=stepen2(a, n);
    printf("%.3f", s);
}


float stepen1(float a, int n)
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

float stepen2(float a, int n)
{

}