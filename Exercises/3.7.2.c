#include <stdio.h>
#include <string.h>

int main(void)
{
    float i;
    char ch;

    printf ("Tips\n");
    for (i = 1.0; i <= 101.0; i=i+1.0)
    {
        printf("%f %f %f %f\n", i, i+i*.1, i+i*.15, i+i*.2);
        printf("Do you want to continue? (y/n): ");
        ch = getchar();
        printf("\n");
        if (ch == 'n')
        {
            break;
        }
    }

    return 0;
}