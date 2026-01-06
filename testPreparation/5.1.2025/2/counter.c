#include <stdio.h>
#include "counter.h"

long sum = 0;

static long nextodd() {
    static long odd = -1;
    odd += 2;
    return odd;
}

void addoddtosum() {
    sum += nextodd();
}