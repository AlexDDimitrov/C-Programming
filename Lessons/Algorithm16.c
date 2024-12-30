#include <stdio.h>
//Сумата от цифрите на дадено число//
void main ()
{
    int s, n=0;
    while (n<1)
    {
        printf ("n = ");
        scanf("%d", &n);
    }
    s=0;
    while (n!=0)
    {   
        s=s+n%10;
        n=n/10;
    } 
    printf("s = %d", s);
}
