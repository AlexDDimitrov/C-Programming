#include <stdio.h>
//мах от 3 числа 1 вариант//
void main ()
{
    int a, b, c, m, i;
    printf ("a = ");
    scanf("%d", &a);
    printf ("b = ");
    scanf("%d", &b);
    printf ("c = ");
    scanf("%d", &c);
    m=a;
    i=1;
    if (a>b) 
    {
       if (a>c) printf("%d", a);
       else printf("%d", c);
    }
    else 
       if (b>c) printf("%d", b);
       else printf("%d", c);
    printf("a=%d, b=%d, c=%d", a, b, c);
}
