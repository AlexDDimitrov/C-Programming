#include "sum.h"

long sum = 0;

static long nextfact() {
    static long nextFact = 1;
    static long n = 1;

    nextFact *= n;
    n++;

    return nextFact;
}

void addfacttosum() {
    sum += nextfact();
}