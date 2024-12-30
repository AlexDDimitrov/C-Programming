#include <stdio.h>
//Дали дадено ест. число е просто или не 1 вариант//
void main ()
{
    int n=0, i;
    while (n<2)
    {
        printf ("n = ");
        scanf("%d", &n);
    }
    i=2;
    while (n%i!=0)
    {
        i++;
    }
    if (n==i) printf("Yes");
    else printf("No");
}
