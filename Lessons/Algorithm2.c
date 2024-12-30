#include <stdio.h>
//Промени стойността на две променливи 2 вариант//
void main ()
{
    int a, b;
    printf ("a = ");
    scanf("%d", &a);
    printf ("b = ");
    scanf("%d", &b);
   a=a+b;
   b=a-b;
   a=a-b;
   printf("a=%d, b=%d", a, b);
}
