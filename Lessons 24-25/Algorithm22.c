#include <stdio.h>
//Записване на число м с четните цифри на н//
void main ()
{
    int n, i, yes, m, b;

    while (n<1)
    {
        printf("n=");
        scanf("%d", &n);
    }
    m=0;
    i=1;
    yes=0;
    while (n>0) 
    {
        b=n%10; 
        n=n/10;
        if (b%2==0)
        {
            b=b*i;
            m=m+b;
            yes=1;
            i=i*10;
        }
    }
    if (yes>0) printf ("m=%d", m);
    else printf ("There is not a single even number");
    
    
}
