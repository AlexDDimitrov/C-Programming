#include <stdio.h>
//мах от n числа - 2 вариант//
void main ()
{
    int a, m, n, i;
    while (n<1)
    {
        printf ("n = ");
        scanf("%d", &n);
    }
    printf ("a= ");
    scanf("%d", &a);
    m=a;
    i=1;
    do 
    {
        if (n==1) break;
        printf ("a= ");
        scanf("%d", &a);
        if (a>m) m=a;
        i++;
    }while (i<n);
    printf("max = %d", m);
}