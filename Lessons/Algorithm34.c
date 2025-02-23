#include <stdio.h>
// програма която превръща ма//
void main() 
{
    int c;

    printf("Enter symbol\n");
    scanf("%c", &c);

    switch (c)
    {
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            c = c - 32;
            printf("%c\n", c);
            break;
        default:
            printf("%c\n", c);
            break;
    }
}