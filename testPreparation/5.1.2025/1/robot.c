#include <stdio.h>

void printDiodes(unsigned char diodes) {
    for (int i = 0; i < 8; i++) {
        if((1<<i) & diodes) {
            printf("Diode on\n");
        } else {
            printf("Diode off\n");
        }
    }
}

void main() {
    unsigned char diodes = 0;
    diodes = 97;
    printDiodes(diodes);
}
