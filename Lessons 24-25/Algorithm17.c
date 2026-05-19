#include <stdio.h>
//Kолко пъти дадена цифра се среща в записа на дадено число//
void main ()
{
    int c=0, n=0, a=0, b;
    while (a<1)
    {
        printf ("a = ");
        scanf("%d", &a);
    }
    while (n<1)
    {
        printf ("n = ");
        scanf("%d", &n);
    }
    do{
    b=a%10;
    if (b==n)
    {   
        c++;
    } 
    a=a/10;
    } while(a!=0);
    printf("c = %d", c);
}
