#include <stdio.h>
//сума от 1 до н чила 1 вариант//
void main ()
{
    int a, s, n, i;
    printf ("n = ");
while (n<1)
    {
        printf ("n = ");
        scanf("%d", &n);
    }
    s=0;
    i=1;
    while (i<=n)
        {
        s=s+i;
        i++;
        }
    printf("sum = %d", s);
}
