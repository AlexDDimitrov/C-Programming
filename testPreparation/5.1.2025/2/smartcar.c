#include <stdio.h>

void printLights(unsigned char lights) {
    for(int i = 0; i < 8; i++) {
        if (lights & (1<<i)) {
            printf("ON\n");
        }
        else {
            printf("Off\n");
        }
    }
}

int main(void) {
    unsigned char lights = 237;
    printLights(lights);
}