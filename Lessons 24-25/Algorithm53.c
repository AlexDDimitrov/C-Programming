#include<stdio.h>
//Flip-flop//
int n = 0;
void flip();
void flop();

void main()
{
    do{
        printf("Enter n = ");
        scanf("%d", &n);
    }while (n<0);
    flip();
}

void flip()
{
    if (n!=0)
    {
        n--;
        printf("Flip\n");
        flop();
    }
}

void flop()
{
    if (n!=0)
    {
        n--;
        printf("Flop\n");
        flip();
    }
}