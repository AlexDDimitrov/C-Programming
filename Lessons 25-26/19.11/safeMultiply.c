#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "safeint.h"
int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Error: Please provide two integers to add.\n");
        return 1;
    }

    int a = safeTurnStrToInt(argv[1]);
    if (safe.errorflag) {
        printf("Error: First argument is out of int range.\n");
        return 1;
    }

    int b = safeTurnStrToInt(argv[2]);
    if (safe.errorflag) {
        printf("Error: Second argument is out of int range.\n");
        return 1;
    }

    safe_multiply(a, b);

    if (safe.errorflag) {
        printf("Error: Integer overflow occurred during multiplication.\n");
        return 1;
    }

    printf("Result: %d\n", safe.value);
    return 0;
}