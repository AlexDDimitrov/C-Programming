#include <stdio.h>
//сума от н чила 1 вариант//
void main ()
{
    int a, s, n, i;
while (n<1)
    {
        printf ("n = ");
        scanf("%d", &n);
    }
    s=0;
    i=1;
    while (i<=n)
    {
        printf ("a = ");
        scanf("%d", &a);
        s=s+a;
        i++;
    } 
    printf("sum = %d", s);
}
