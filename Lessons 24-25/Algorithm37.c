#include <stdio.h>
// програма която превръща малки в големи символи//
void main() 
{
    char c;
    float a, b;
    a = 0;
    b = 0;
    c = 0;

    scanf("%f", &a);
    do {
        scanf(" %c", &c);
        if (c == '=')
        {
            printf("%.2f\n", a);
            break;
        }
        scanf("%f", &b);

        switch (c)
        {
            case '+':
                a = a + b;
                break;
            case '-':
                a = a - b;
                break;
            case '*':
                a = a * b;
                break;
            case '/':
                while (b == 0)
                {
                    printf("Error. Enter again.\n");
                    scanf("%f", &b);
                }
                a = a / b;
                break;
            default:
                break;
        }
    } while (c!='=');
}