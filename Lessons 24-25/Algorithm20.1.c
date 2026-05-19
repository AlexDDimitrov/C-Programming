#include <stdio.h>
//Да се изведат всички прости делители на ест. число н и техния брой//
void main()
{
    int a, count, n, i, p;
    do{
        printf("Enter n=");
        scanf("%d", &n);
    } while(n<1);
    count=0;
    i=2;
    p=2;
    while (i<=n) 
    {
       
       if (n%i==0) 
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
    printf("count=%d", count);
}