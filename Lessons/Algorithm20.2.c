#include <stdio.h>
//Да се изведат всички прости делители на ест. число н и техния брой//
int simpleNumber(int n1);
void main()
{
    int a, count, n;
    do{
        printf("Enter n=");
        scanf("%d", &n);
    } while(n<1);
    count = simpleNumber(n);
    printf("count=%d", count);
}

int simpleNumber(int n1)
{
    int p = 2;
    int i = 0;
    int count = 0;
    while (i<=n1) 
    {
       
       if (n1%i==0) 
        {
            p=2; 
            while (i%p!=0) 
            {
                p++;
            }
            if (i==p) 
            {
            printf("i=%d \n", i);
            count=count+1;
            }
        }
        i++;
    }
    return count;
}