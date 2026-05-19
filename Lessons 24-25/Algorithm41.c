#include <stdio.h>

int main(void)
{
    char c;
    float a = 0.0f;
    int b;
    int i = 0, p = 0, m = 1;
    c = getchar(); 

    while (c != '\n')
    {
        if (p == 0) 
        {
            switch (c)
            {
                case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
                    i = 1;
                    break;
                case '+':
                    i = 1;
                    m = 1;
                    break;
                case '-':
                    i = 1;
                    m = 0;
                    break;
                default:
                    i = 0;
                    break;
            }
        }
        else
        {
            switch (c)
            {
                case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
                    i = 1;
                    break;
                case '+': case '-':
                    i = 0;
                    break;
                default:
                    i = 0;
                    break;
            }
        }

        if (i == 0)
            break;

        if (c >= '0' && c <= '9') 
        {
            a = a * 10 + (c - '0');
        }
        else if (c == '.')
        {
            float place = 0.1;
            c = getchar(); 
            while (c >= '0' && c <= '9') 
            {
                a += (c - '0') * place;
                place /= 10;
                c = getchar();
            }
            break;  
        }

        p++; 
        c = getchar(); 
    }

    if (m == 0)
        a = -a; 

    if (i == 1)
    {
        b=a;
        printf("The number can be integrated\n");
        printf("%d\n", b);
    }
    else
    {
        printf("The number can't be integrated\n");
    }

    return 0;
}
