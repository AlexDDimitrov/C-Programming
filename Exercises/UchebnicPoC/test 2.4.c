#include <stdio.h>

int main()
{
    int i;

    for(i=1; i<101; i++)
    {
        printf("%d  ", i);
        if(i%5==0) 
            printf("\n");
    }
}
