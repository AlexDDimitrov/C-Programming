#include <stdio.h>
//намиране на единиците в двоичното представяне на дадено естествено число//
void main ()
{
    int n, s , i;

    while (n<1)
    {
        printf("n=");
        scanf("%d", &n);
    }
    s=0;
    do
    {
        if (n%i!=0)
        {
            s=s+1;
        }
        n=n/2;

    } while (n!=0);
    
    printf ("s=%d", s);
    
    
}
