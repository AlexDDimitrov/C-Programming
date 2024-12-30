#include <stdio.h>
//Записване на число в обратен ред//
void main ()
{
    int n=0, sum;
    while (n<1)
    {
        printf ("n = ");
        scanf("%d", &n);
    }
    sum=0;
    while (n!=0)
    {
        sum=sum*10+n%10;
        n=n/10;
    }
    printf("sum = %d", sum);
}
