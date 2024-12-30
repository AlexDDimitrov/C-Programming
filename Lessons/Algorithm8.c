#include <stdio.h>
//мах от n числа - 1 вариант//
void main ()
{
    int a, m, n, i;
    printf ("n = ");
    scanf("%d", &n);
    printf ("a= ");
    scanf("%d", &a);
    m=a;
    i=1;
    while (i<n)
    {
        if (n==1) break;
        printf ("a= ");
        scanf("%d", &a);
        if (a>m) m=a;
        i++;
    }
    printf("max = %d", m);
}