#include <stdio.h>

int main(void)
{
    unsigned char diodes = 97;

    printf("Diodes state:\n");
    for (int i = 0; i < 8; i++)
    {
        printf("Diode %d: %d\n", i+1, (diodes >> i) & 1);
    }

    return 0;
}
