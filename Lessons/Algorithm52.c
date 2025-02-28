#include<stdio.h>

void binary(int n)
{
    if(n>0)
    {
        binary(n/2);
        printf("%d", n%2);
    }
}

void main()
{
    int n;
    do{
        printf("Enter n = ");
        scanf("%d", &n);
    }while (n<0);
    binary(n);
}