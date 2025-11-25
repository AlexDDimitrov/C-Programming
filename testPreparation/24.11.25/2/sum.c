#include <stdio.h>
#include <stdlib.h>+
#include "helpers.h"

int main(int argc, char **argv) {
    int a = atoi(argv[1]);

    int result = sum(a);
    printf("%d", result);
}