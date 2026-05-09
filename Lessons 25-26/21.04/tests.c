#include <stdio.h>
#include "DynamicArray.h"

int main(void) {
    DynamicArray arr = init(4);
    if (arr.buffer != NULL) {
        printf("Success!");
    }
    release(&arr);

    return 0;
}