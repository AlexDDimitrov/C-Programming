#include <stdio.h>
//мах от 3 числа 2 вариант//
void main ()
{
    int a, b, c, i, m;
    printf ("a = ");
    scanf("%d", &a);
    printf ("b = ");
    scanf("%d", &b);
    printf ("c = ");
    scanf("%d", &c);
    m=a;
    i=1;
    if (b>m) m=b;
    if (c>m) m=c;
    printf ("m= %d", m);
}

