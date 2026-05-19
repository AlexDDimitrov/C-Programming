#include <stdio.h>
//сума от н чила 2 вариант//
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
    do  
    {
        printf ("a = ");
        scanf("%d", &a);
        s=s+a;
        i++;
    } while (i<=n);
    printf("sum = %d", s);
}
