#include<stdio.h>
//staircase//
/*__
    |__
       |__
          |__
             |__*/
void staircase(int n, int i)
{
    if (n>0)
    {
        for (int j=0; j<i; j++) printf("  ");
        printf("|");
        printf("___\n");
        staircase(n-1, i+2);
    }
}

void main()
{
    int n;
    do{
        printf("Enter n = ");
        scanf("%d", &n);
    }while (n<1);
    printf("__\n");
    staircase(n, 1);
}