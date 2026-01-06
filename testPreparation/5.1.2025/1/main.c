#include <stdio.h>

#include "sum.h"

void main() {
    for (int j = 0; j < 7; j++) {
        addfactorieltosum();
    }
    printf("sum = %ld\n", sum);
    return 0;
}