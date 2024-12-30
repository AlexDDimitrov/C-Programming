#include <stdio.h>
//Промени стойността на две променливи 1 вариант//
void main ()
{
    int a, b, c;
    printf ("a = ");
    scanf("%d", &a);
    printf ("b = ");
    scanf("%d", &b);
    c=a;
    a=b;
    b=c;
   printf("a=%d, b=%d", a, b);
}
