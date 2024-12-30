#include <stdio.h>

void main() 
{
    float a, b, x, m, n;

    
    printf("a= ");
    scanf("%f", &a);
    printf("b= ");
    scanf("%f", &b);


  
    if (a == 0) 
        if (b == 0) 
        {
            printf("Every answer is right\n");
        } 
        else 
        {
            printf("There is no answer\n");
        } 
        else
        if (a > 0) 
        {
        
            m=-b/a;
            printf(" x < %f\n", m);
        } 
        else
        {
            n=-a/b;
            printf("x < %f\n", n);
        }
}
