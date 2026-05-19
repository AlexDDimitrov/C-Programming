#include <stdio.h>
// програма която извежда всички символи от ASCII таблицата//
void main() 
{
    int c;

    for (c=0; c<=255; c++)
        {
            printf("\n%c -> %d", c, c);
        }
}