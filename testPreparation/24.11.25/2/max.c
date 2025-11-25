#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main(int argc, char **argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    MAX(a, b);
}