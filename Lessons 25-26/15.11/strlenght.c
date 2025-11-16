#include "myStrings.h"
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: Please provide a string as an argument.\n");
        return 1;
    }
    int length = strLength(argv[1]);
    printf("Length of the string: %d\n", length);
    return 0;
}