#include <stdio.h>

void printLights(unsigned char lights) {
    for (int i = 0; i < 8; i++) {
        if (!(lights & (1 << i))) {
            printf("OFF %d\n", i+1);
        }
    }
}

int main(void)
{
    unsigned char lights = 189;
    printLights(lights);
}
