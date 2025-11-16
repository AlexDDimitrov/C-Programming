#include "myStrings.h"
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Error: Please provide two strings as arguments.\n");
        return 1;
    }
    if (strlen(argv[1]) + strlen(argv[2]) + 1 > 50) {
        printf("Error: Destination buffer is not large enough.\n");
        return 1;
    }
    printf("%s\n", strconcat(argv[1], argv[2]));
}