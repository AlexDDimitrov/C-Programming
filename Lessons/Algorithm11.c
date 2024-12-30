#include <stdio.h>
//сума от 1 до н чила 2 вариант//
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
        s=s+i;
        i++;
    }  while (i<=n);
    printf("sum = %d", s);
}
