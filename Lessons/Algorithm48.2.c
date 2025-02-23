#include<stdio.h>
//n!//
int fact1(int n);
int fact2(int n);
void main()
{
    int n;
    do{
        printf("n=");
        scanf("%d", &n);
    } while(n<1);
    
    printf("\n%d", fact1(n));
    printf("\n%d", fact2(n));
}

int fact1(int n)
{
    int p=1, i;
    for(i=1;i<=n;i++) p=p*i;
    return p;
}

int fact2(int n)
{
    if (n==0) return 1;
    else return n*fact2(n-1);
}