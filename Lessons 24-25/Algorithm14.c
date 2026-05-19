#include <stdio.h>
//среден успех 1 вариант//
void main ()
{
    int n, i;
    float sum, a, avr;
while (n<1)
    {
        printf ("n = ");
        scanf("%d", &n);
    }
    sum=0;
    i=1;
    while (i<=n)
    {   
        printf ("a = ");
        scanf("%f", &a);
        if (a>=2 && a<=6) 
        {
            sum=sum+a;
            i++;    
        } 
    }
    avr=sum/n;
    printf("avr = %.2f", avr);
}
