#include <stdio.h>
//Дали дадено ест. число е просто или не 2 вариант//
void main ()
{
    int n=0, i;
    while (n<2)
    {
        printf ("n = ");
        scanf("%d", &n);
    }
    i=2;
    do{
        i++;
    } while (n%i!=0);
    if (n==i) printf("Yes");
    else printf("No");
}
