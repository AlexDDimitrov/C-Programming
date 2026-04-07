#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"
#include "util.h"

void assertIndexInBounds(DynamicArray * dynArr, uint index) {
  if (index >= dynArr->size) {
    printf("Index out of bounds");
    exit(1);
  }
}

DynamicArray init(uint capacity) {
  if (capacity < 0) {
    printf("Invalid capacity\n");
    exit(1);
  }
  DynamicArray newDynamicArray = {
    .size = 0,
    .capacity = capacity,
    .buffer = NULL
  };

  if (newDynamicArray.capacity > 0) {
    newDynamicArray.buffer = calloc(newDynamicArray.capacity, sizeof(DynArrType));
    ASSERT_ALLOC(newDynamicArray.buffer);
  }

  return newDynamicArray;
}

static void resize(DynamicArray * dynArr, uint newSize) {
  uint oldCapacity = dynArr->capacity;
  if (newSize > dynArr->capacity) {
    if (dynArr->capacity == 0) {
      dynArr->capacity = 1;
    }
    while (dynArr->capacity < newSize) {
      dynArr->capacity *= 2;
    }
  }
  if (oldCapacity != dynArr->capacity) {
    if (dynArr->capacity == 0) {
      free(dynArr->buffer);
      dynArr->buffer = NULL;
    } else {
      DynArrType * temp = (DynArrType *)realloc(dynArr->buffer, sizeof(DynArrType) * dynArr->capacity);
      ASSERT_ALLOC(temp);
      dynArr->buffer = temp;
    }
  }
  dynArr->size = newSize;
}

void pushBack(DynamicArray * dynArr, DynArrType value) {
  uint oldSize = dynArr->size;
  uint newSize = oldSize + 1;
  resize(dynArr, newSize);
  dynArr->buffer[oldSize] = value;
}

void push(DynamicArray * dynArr, uint index, DynArrType value) {
  uint oldSize = dynArr->size;
  uint newSize = oldSize + 1;
  resize(dynArr, newSize);
  for (int i = newSize - 1; i > index; i--) {
    dynArr->buffer[i] = dynArr->buffer[i - 1];
  }
  dynArr->buffer[index] = value;
}

void pushFront(DynamicArray * dynArr, DynArrType value) {
  push(dynArr, 0, value);
}

DynArrType pop(DynamicArray * dynArr, uint index) {
  assertIndexInBounds(dynArr, index);
  uint newSize = dynArr->size - 1;
  DynArrType value = dynArr->buffer[index];
  for (int i = index; i < newSize; i++) {
    dynArr->buffer[i] = dynArr->buffer[i+1];
  }
  resize(dynArr, newSize);
  return value;
}

DynArrType popBack(DynamicArray * dynArr) {
  if (dynArr->size == 0) {
    printf("Dynamic array is empty\n");
    exit(1);
  }
  return pop(dynArr, dynArr->size - 1);
}

DynArrType popFront(DynamicArray * dynArr) {
  if (dynArr->size == 0) {
    printf("Dynamic array is empty\n");
    exit(1);
  }
  return pop(dynArr, 0);
}

DynArrType get(DynamicArray * dynArr, uint index) {
  assertIndexInBounds(dynArr, index);
  return dynArr->buffer[index];
}

void set(DynamicArray * dynArr, uint index, DynArrType value) {
  assertIndexInBounds(dynArr, index);
  dynArr->buffer[index] = value;
}

void release(DynamicArray * dynArr) {
  free(dynArr->buffer);
  dynArr->buffer = NULL;
  dynArr->size = 0;
  dynArr->capacity = 0;
}

int getIndex(DynamicArray * dynArr, uint index) {
  for (int i = 0; i < dynArr->size; i++) {
    if (dynArr->buffer[i] == index) {
      return i;
    }
  }
  return index;
}