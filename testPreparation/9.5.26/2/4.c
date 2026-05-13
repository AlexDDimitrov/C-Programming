#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef double arrType;

typedef struct Arr {
    arrType * buffer;
    uint size;
    uint capacity;
} Arr;

void check_alloc(arrType * ptr) {
    if (ptr == NULL) {
        printf("Error allocating memory");
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
    if (newSize > arr->capacity) {
        if (arr->capacity == 0) {
            arr->capacity = 1;
        }
        while (arr->capacity < newSize) {
            arr->capacity *= 2;
        }
    }
    else if (newSize <= arr->capacity / 4) {
        arr->capacity /= 2;
    }
    arrType * temp = realloc(arr->buffer, sizeof(arrType) * arr->capacity);
    check_alloc(temp);
    arr->buffer = temp;
}

void pushBack(Arr * arr, arrType value) {
    uint oldSize = arr->size;
    uint newSize = oldSize +1;
    resize(arr, newSize);
    arr->buffer[oldSize] = value;
    arr->size++;
}

void printdynarr(Arr arr) {
    for (uint i = 0; i < arr.size; i++) {
        printf("%lf, ", arr.buffer[i]);
    }
    printf("\n");
}

void main() {
    Arr arr = init(2);
    pushBack(&arr, 1);
    pushBack(&arr, 2);
    pushBack(&arr, 3);
    printdynarr(arr);
}

/////////////////////////
//допълнително за упражнение:

void push(Arr * arr, uint index, arrType value) {
    if (index > arr->size) {
        printf("Out of bounds!");
        exit(1);
    }
    uint oldSize = arr->size;
    uint newSize = oldSize + 1;
    resize(arr, newSize);
    for (int i = oldSize; i > index; i--) {
        arr->buffer[i] = arr->buffer[i - 1];
    }
    arr->buffer[index] = value;
    arr->size = newSize;
}

void pushFront(Arr * arr, arrType value) {
    push(arr, 0, value);
}

void pop(Arr * arr, uint index) {
    if(index >= arr->size) {
        printf("Out of bounds!");
        exit(1);
    }
    if (arr->size == 0) {
        printf("Dynamic array is empty\n");
        exit(1);
    }
    uint newSize = arr->size - 1;
    for (uint i = index; i < newSize; i++) {
        arr->buffer[i] = arr->buffer[i + 1];
    }
    resize(arr, newSize);
    arr->size = newSize;
}

void popBack(Arr * arr) {
    if (arr->size == 0) {
        printf("Dynamic array is empty\n");
        exit(1);
    }
    pop(arr, arr->size-1);
}

void popFront(Arr * arr) {
    if (arr->size == 0) {
        printf("Dynamic array is empty\n");
        exit(1);
    }
    pop(arr, 0);
}

arrType get (Arr * arr, uint index) {
    if(index >= arr->size) {
        printf("Out of bounds!");
        exit(1);
    }
    return arr->buffer[index];
}

void set (Arr * arr, uint index, arrType value) {
    if(index >= arr->size) {
        printf("Out of bounds!");
        exit(1);
    }
    arr->buffer[index] = value;
}

void release (Arr * arr) {
    free(arr->buffer);
    arr->buffer = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int getIndex(Arr * arr, arrType value) {
    for (uint i = 0; i < arr->size; i++){
        if(arr->buffer[i] == value) return i;
    }
    return -1;
}