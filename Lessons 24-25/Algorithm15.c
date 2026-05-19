#include <stdio.h>
//среден успех 2 вариант//
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
    i=0;
    do
    {   printf ("a = ");
        scanf("%f", &a);
        if (a>=2 && a<=6) 
        {
            sum=sum+a;
            i++;    
        } 
    } while (i<n);
    avr=sum/n;
    printf("avr = %.2f", avr);
}
