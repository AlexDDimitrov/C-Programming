#include <stdio.h>

#include "sum.h"

long sum = 0;

static long nextfactoriel(void) {
    static int n = 1;
    static long fact = 1;

    fact *= n;
    n++;

    return fact;
}

void addfactorieltosum() {
    sum  += nextfactoriel();
}