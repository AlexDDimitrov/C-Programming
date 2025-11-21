#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "safeint.h"
int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Error: Please provide two integers to add.\n");
        return 1;
    }
    int a;
    int b;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    safe.value = safe_add(a, b);
    if (safe.errorflag) {
        printf("Error: Integer overflow occurred during addition.\n");
        return 1;
    }
    printf("Result: %d\n" , safe.value);
    return 0;

}