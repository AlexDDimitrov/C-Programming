#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef int dint;
typedef unsigned int uint;

typedef struct {
  dint * buffer;
  uint size;
  uint capacity;
} DynamicArray;

DynamicArray init(uint capacity);

void pushBack(DynamicArray * dynArr, dint value);
void pushFront(DynamicArray * dynArr, dint value);
void push(DynamicArray * dynArr, uint index, dint value);

void popBack(DynamicArray * dynArr);
void popFront(DynamicArray * dynArr);
void pop(DynamicArray * dynArr, uint index);

dint get(DynamicArray * dynArr, uint index);
void set(DynamicArray * dynArr, uint index, dint value);

void release(DynamicArray * dynArr);

int getIndex(DynamicArray * dynArr, uint index);

#endif