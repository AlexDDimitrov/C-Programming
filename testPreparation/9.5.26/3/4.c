#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef double arrType;

typedef struct Arr {
    arrType * buffer;
    uint size;
    uint capacity;
} Arr;

void check_alloc(void * ptr) {
    if (ptr == NULL) {
        printf("Error allocating memory!");
        exit(1);
    }
}

Arr init(uint capacity) {
    Arr arr = {
        .buffer = NULL,
        .capacity = capacity,
        .size = 0
    };

    if (capacity > 0) {
        arr.buffer = calloc(capacity, sizeof(arrType));
        check_alloc(arr.buffer);
    }
    return arr;
}

void resize(Arr * arr, uint newSize) {
    uint oldcapacity = arr->capacity;
    if(arr->capacity < newSize) {
        if(arr->capacity == 0) {
            arr->capacity = 1;
        }
        while(arr->capacity < newSize) {
            arr->capacity *= 2;
        }
    } else if((arr->capacity/4) > newSize) {
        arr->capacity /= 2;
    }

    if(arr->capacity != oldcapacity) {
        if(arr->capacity == 0) {
            free(arr->buffer);
            arr->buffer = NULL;
            arr->size = 0;
        } else {
            arrType * temp = realloc(arr->buffer, sizeof(arrType) * arr->capacity);
            check_alloc(temp);
            arr->buffer = temp;
        }
    }
}

void pushBack(Arr * arr, arrType value) {
    uint oldSize = arr->size;
    uint newSize = oldSize+1;
    resize(arr, newSize);
    arr->buffer[oldSize] = value;
    arr->size++;
}

void printdynarr(Arr * arr) {
    for (uint i = 0; i < arr->size; i++) {
        printf("%lf, ", arr->buffer[i]);
    }
    printf("\n");
}

int main(void) {
    Arr arr = init(2);
    pushBack(&arr, 1);
    pushBack(&arr, 2);
    pushBack(&arr, 3);
    printdynarr(&arr);
}
