#include <stdio.h>
//Разлика на 2 числа//
void main ()
{
    int a, b;
    printf ("a = ");
    scanf("%d", &a);
    printf ("b = ");
    scanf("%d", &b);
    if (a>b) a=a-b;
    else b=b-a;
    printf("a = %d, b = %d", a, b);
}
