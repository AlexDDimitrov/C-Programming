#include "myStrings.h"
#include <stdio.h>


int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Error: Please provide two strings to compare.\n");
        return 1;
    }
    int result = strcompare(argv[1], argv[2]);
    printf("Comparison result: %d\n", result);
    return 0;
}