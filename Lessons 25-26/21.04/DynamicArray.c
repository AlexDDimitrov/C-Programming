#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"

void assert_alloc(DynamicArray * arr) {
    if (arr->buffer == NULL) {
        printf("Error: Problem with allocating memory.\n");
        exit(1);
    }
}

void release(DynamicArray * dynArr) {
    free(dynArr->buffer);
    dynArr->buffer = NULL;
    dynArr->capacity = 0;
    dynArr->size = 0;
}

DynamicArray init(uint capacity) {
    if (capacity < 0) {
        printf("Error: Unable to initialise the array due to not supporting negative size.");
        exit(1);
    }

    DynamicArray newDynamicArray = {
        .size = 0,
        .capacity = capacity,
        .buffer = NULL
    };

    if (newDynamicArray.capacity > 0) {
        newDynamicArray.buffer = calloc(newDynamicArray.capacity, sizeof(dint));
        assert_alloc(&newDynamicArray);
    }

    return newDynamicArray;
}

void resize(DynamicArray * dynArr, uint newSize) {
    uint oldCapacity = dynArr->capacity;
    if (newSize > dynArr->capacity) {
        
    }
}

void pushFront(DynamicArray * dynArr, dint value) {

}

void push(DynamicArray * dynArr, uint index, dint value) {

}

void pushBack(DynamicArray * dynArr, dint value) {

}