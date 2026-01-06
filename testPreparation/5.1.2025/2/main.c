#include <stdio.h>
#include "counter.h"

int main(void) {
    for(int j = 0; j<10; j++) {
        addoddtosum();
        printf("%d\n", sum);
    }
}