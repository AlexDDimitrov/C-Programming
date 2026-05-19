#include <stdio.h>
#include <conio.h>

int main(void)
{
    char c;
    char a;
    int i, p, m;
    p=0;
    i=0;
    while (c != '\n')
    {
    c = getchar();
    if (p==0)
    {
        switch (c)
        {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
            {
            i=1;
            break;
            }
        case '+':
            {
            i=1;
            m=1;
            break;
            }
        case'-':
            {
            i=1;
            m=0;
            break;
            }
        case '\n': break;
        default:
            {
            i=0;
            break;
            }
    }
    }
    else
    {
        switch (c)
        {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
            {
            i=1;
            break;
            }
        case '\n': break;
        case '+': case '-':
            {
            i=0;
            break;
            }
        default:
            {
            i=0;
            break;
            }
        }
        if (i==0) break;
    }
    p++;
    }
    if (i == 1)
        {
        printf("The number can be integrated\n");
        }
    else
        printf("The number can't be integrated\n");
}
