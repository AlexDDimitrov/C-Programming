#include <stdio.h>
//програма за намиране на а на н степен//
void main ()
{
    int n , i, m;
    float p, a;
    do
    {
        printf("a=");
        scanf("%f", &a);
    } while (a==0);
    printf("n=");
    scanf("%d", &n);
    if (n<0) m=-n;
    else m=n;
    p=1;
    i=0;
    while (i<m)
    {
        p=p*a;
        i=i+1;
    }
    if (n<0) p=1/p;
    printf("p=%f", p);
}
