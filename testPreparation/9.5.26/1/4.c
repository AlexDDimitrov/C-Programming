#include <stdio.h>
#include <stdlib.h>

typedef double arrType;
typedef unsigned int uint;

typedef struct {
  arrType * buffer;
  uint size;
  uint capacity;
} DynamicArray;

void check_alloc(arrType * buffer) {
    if (buffer == NULL) {
        printf("Error allocating memory");
        exit(1);
    }
}

DynamicArray init(uint capacity) {
    if (capacity < 0) {
        printf("Error");
        exit(1);
    }

    DynamicArray arr = {
        .buffer = NULL,
        .size = 0,
        .capacity = capacity
    };

    if (capacity > 0) {
        arr.buffer = calloc(capacity, sizeof(arrType));
        check_alloc(arr.buffer);
    }

    return arr;
}

void resize(DynamicArray * arr, uint size) {
    uint oldcapacity = arr->capacity;
    if (size > arr->capacity) {
        if(arr->capacity == 0) {
            arr->capacity = 1;
        }
        while (arr->capacity < size) {
            arr->capacity *= 2;
        }
    } else if (size <= arr->capacity / 4) {
        arr->capacity /= 2;
    }
    if (oldcapacity != arr->capacity) {
        if (arr->capacity == 0) {
            free(arr->buffer);
            arr->buffer = NULL;
        } else {
            arrType *temp = realloc(arr->buffer, sizeof(arrType) * arr->capacity);
            check_alloc(temp);
            arr->buffer = temp;
        }
    }
}

void pushBack (DynamicArray * arr, arrType value) {
    uint oldSize = arr->size;
    uint newSize = oldSize+1;
    resize(arr, newSize);
    arr->buffer[oldSize] = value;
    arr->size = newSize;
}

void printArr(DynamicArray arr) {
    for (uint i = 0; i < arr.size; i++) {
        printf("%lf, ", arr.buffer[i]);
    }
    printf("\n");
}

void main() {
    DynamicArray arr = init(2);
    pushBack(&arr, 1);
    pushBack(&arr, 2);
    pushBack(&arr, 3);
    printArr(arr);
}

/////////////////////////
//допълнително за упражнение:

void push(DynamicArray * arr, uint index, arrType value) {
    uint oldSize = arr->size;
    uint newSize = oldSize+1;
    resize(arr, newSize);
    for(uint i = (newSize-1); i > index; i++) {
        arr->buffer[i] = arr->buffer[i-1];
    }
    arr->buffer[index] = value;
    arr->size = newSize;
}

void pushFront(DynamicArray * arr, arrType value) {
    push(arr, 0, value);
}

void pop(DynamicArray * arr, uint index) {
    if(index >= arr->size) {
        printf("Out of bounds!");
        exit(1);
    }
    uint newSize = arr->size - 1;
    for(uint i = index; i < newSize; i++) {
        arr->buffer[i] = arr->buffer[i+1];
    }
    resize(arr, newSize);
    arr->size = newSize;
}

void popBack(DynamicArray * arr) {
    if (arr->size == 0) {
        printf("Dynamic array is empty\n");
        exit(1);
    }
    pop(arr, arr->size-1);
}

void popFront(DynamicArray * arr) {
    if (arr->size == 0) {
        printf("Dynamic array is empty\n");
        exit(1);
    }
    pop(arr, 0);
}

arrType get (DynamicArray * arr, uint index) {
    if(index >= arr->size) {
        printf("Out of bounds!");
        exit(1);
    }
    return arr->buffer[index];
}

void set (DynamicArray * arr, uint index, arrType value) {
    if(index >= arr->size) {
        printf("Out of bounds!");
        exit(1);
    }
    arr->buffer[index] = value;
}

void release (DynamicArray * arr) {
    free(arr->buffer);
    arr->buffer = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int getIndex(DynamicArray * arr, arrType value) {
    if(value >= arr->size) {
        printf("Out of bounds!");
        exit(1);
    }
    for (uint i = 0; i < arr->size; i++){
        if(arr->buffer[i] == value) return i;
    }
    return value;
}