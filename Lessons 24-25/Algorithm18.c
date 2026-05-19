#include <stdio.h>
//Делителите на дадено число//
void main ()
{
    int c, n=0, i;
    while (n<1)
    {
        printf ("n = ");
        scanf("%d", &n);
    }
    c=0;
    i=1;
    while (i<=n)
    {
        if (n%i==0)
        {
          printf("i = %d \n", i);  
          c++;
        }
        i++;
    }
    printf("c = %d \n", c);
}
