#include <stdio.h>

void printLights(unsigned char lights) {
    for(int k = 0; k < 8; k++) {
        if (lights & (1<<k)) {
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