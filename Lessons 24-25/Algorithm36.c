#include <stdio.h>
// програма която превръща малки в големи символи//
void main() 
{
    char c;
    do {
        scanf("%c", &c);
        if (c>='a' && c<='z')
        {
            c=c-32;
        }
        printf("%c", c);
    }while (c!='.');
}