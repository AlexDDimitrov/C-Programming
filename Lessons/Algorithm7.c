#include <stdio.h>
//мах от 100 числа//
void main ()
{
    int a, m, n, i;
    printf ("a = ");
    scanf("%d", &a);
    m=a;
    i=1;
    if (i<=100) 
    {
        while (i<=100)
        {
        printf ("a= ");
        scanf("%d", &a);
        if (a>m) m=a;
        i=i++;
        }
    }
    else printf("max = %d", m);
}
