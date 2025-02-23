#include <stdio.h>
//пирамида от символи//
void pyramid(int n, char c);
void main(void)
{
    int n;
    char c;
    printf("Emter n: ");
    scanf("%d", &n);
    printf("Emter c: ");
    scanf(" %c", &c);
    pyramid(n, c);
}

void pyramid(int n, char c)
{
    int i, k;
    for (i=1; i<=n; i++)
    {
        for (k=1; k<=i; k++)
        {
            printf("%2c", c);
        }
        printf("\n");
    }
}

