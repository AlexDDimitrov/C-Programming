#include <stdio.h>
// програма която определя какъв вид символ е//
void main() 
{
    int c;
    int s, a, m, p;
    printf("Enter symbol\n");
    while ((c = getchar()) != '\n' && c != EOF)
    {
    scanf("%c", &c);
    a = 0;
    m = 0;
    p = 0;
    switch (c)
    { 
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            s++;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
            a++;
            break;
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            m++;
            break;
        default:
            p++;
            break; 
    }
    }
    
    printf("Digits: %d\n", s);
    printf("Capital letters: %d\n", a);
    printf("Small letters: %d\n", m);
    printf("Special symbols: %d\n", p);
}