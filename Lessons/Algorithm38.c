#include <stdio.h>
#include <conio.h>
// програма която извежда азки кодове//
void main() 
{
    unsigned char c;
    do
    {
        c = getch();
        printf("\n%d", c);
    } while (c!=27);
}