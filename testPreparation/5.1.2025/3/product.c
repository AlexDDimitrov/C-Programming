#include <stdio.h>
#include "product.h"

long product = 1;
 
static long nexteven() {
    static long n = 0;
    n+=2;
    return n;
}

void multiplywitheven() {
    product *= nexteven();
    printf("%ld\n", product);
}