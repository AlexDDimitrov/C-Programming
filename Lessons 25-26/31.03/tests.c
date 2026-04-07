#include <stdio.h>
#include "DynamicArray.h"

#define ASSERT_TEST(MESSAGE, CONDITION) \
  if (CONDITION) { \
    printf(MESSAGE ":PASSED\n"); \
  } else { \
    printf(MESSAGE ":FAILED\n"); \
  }

void testDynamicArrayInitializationWithCapacityDifferentThanZero() {
  int initialCapacity = 2;
  DynamicArray dynArr = init(initialCapacity);

  ASSERT_TEST("Initial size of dynamic array should be equal to 0", dynArr.size == 0);
  ASSERT_TEST("Initial capacity of dynamic array should be equal to passed capacity", dynArr.capacity == initialCapacity);
  ASSERT_TEST("Buffer of dynamic array inited with capacity not equal to 0 should be not NULL", dynArr.buffer != NULL);
}

void testPushElementsInDynamicArray() {
  int initialCapacity = 2;
  DynamicArray dynArr = init(initialCapacity);

  pushBack(&dynArr, 5);
  pushBack(&dynArr, 6);
  pushBack(&dynArr, 8);

  push(&dynArr, 1, 99);

  ASSERT_TEST("When pushing back 5, 6, 8 in dynamic array and pushing 99 on index 1, the buffer of the dynamic array should have values 5, 99, 6, 8", 
    dynArr.buffer[0] == 5 
    && dynArr.buffer[1] == 99
    && dynArr.buffer[2] == 6
    && dynArr.buffer[3] == 8
  );
}

void testPushingBackElementsInDynamicArray() {
  int initialCapacity = 2;
  DynamicArray dynArr = init(initialCapacity);

  pushBack(&dynArr, 5);
  pushBack(&dynArr, 6);
  pushBack(&dynArr, 8);

  ASSERT_TEST("When pushing 5, 6, 8 in dynamic array the buffer of the dynamic array should have values 5, 6, 8", 
    dynArr.buffer[0] == 5 
    && dynArr.buffer[1] == 6
    && dynArr.buffer[2] == 8
  );

  ASSERT_TEST(
    "Dynamic array capacity should be doubled, when pushing more elements than the initial capacity", 
    dynArr.capacity == initialCapacity * 2
  );
}

void testPushFrontElementsInDynamicArray() {
  int initialCapacity = 2;
  DynamicArray dynArr = init(initialCapacity);

  pushBack(&dynArr, 5);
  pushBack(&dynArr, 6);

  pushFront(&dynArr, 8);

  ASSERT_TEST("When pushing back 5, 6 in dynamic array and pushing front 8, the buffer of the dynamic array should have values 8, 5, 6", 
    dynArr.buffer[0] == 8 
    && dynArr.buffer[1] == 5
    && dynArr.buffer[2] == 6
  );
}

void testPopElementsInDynamicArray() {
  int initialCapacity = 2;
  DynamicArray dynArr = init(initialCapacity);

  pushBack(&dynArr, 5);
  pushBack(&dynArr, 6);
  pushBack(&dynArr, 8);

  pop(&dynArr, 1);

  ASSERT_TEST("When pushing back 5, 6, 8 in dynamic array and popping element on index 1, the buffer of the dynamic array should have values 5, 8", 
    dynArr.buffer[0] == 5 
    && dynArr.buffer[1] == 8
    && dynArr.size == 2
  );
}

void testPopBackElementsInDynamicArray() {
  int initialCapacity = 2;
  DynamicArray dynArr = init(initialCapacity);

  pushBack(&dynArr, 5);
  pushBack(&dynArr, 6);
  pushBack(&dynArr, 8);

  popBack(&dynArr);

  ASSERT_TEST("When pushing back 5, 6, 8 in dynamic array and popping back element, the buffer of the dynamic array should have values 5, 6", 
    dynArr.buffer[0] == 5 
    && dynArr.buffer[1] == 6
    && dynArr.size == 2
  );
}

void testPopFrontElementsInDynamicArray() {
  int initialCapacity = 2;
  DynamicArray dynArr = init(initialCapacity);

  pushBack(&dynArr, 5);
  pushBack(&dynArr, 6);
  pushBack(&dynArr, 8);

  popFront(&dynArr);

  ASSERT_TEST("When pushing back 5, 6, 8 in dynamic array and popping front element, the buffer of the dynamic array should have values 6, 8", 
    dynArr.buffer[0] == 6 
    && dynArr.buffer[1] == 8
    && dynArr.size == 2
  );
}

void testGetElementFromDynamicArray() {
  int initialCapacity = 2;
  DynamicArray dynArr = init(initialCapacity);

  pushBack(&dynArr, 5);
  pushBack(&dynArr, 6);
  pushBack(&dynArr, 8);

  ASSERT_TEST("When pushing back 5, 6, 8 in dynamic array and getting element on index 1, the result should be equal to 6", 
    get(&dynArr, 1) == 6
  );
}

void testSetElementFromDynamicArray() {
  int initialCapacity = 2;
  DynamicArray dynArr = init(initialCapacity);

  pushBack(&dynArr, 5);
  pushBack(&dynArr, 6);
  pushBack(&dynArr, 8);

  set(&dynArr, 1, 99);

  ASSERT_TEST("When pushing back 5, 6, 8 in dynamic array and setting element on index 1 to value 99, the buffer of the dynamic array should have values 5, 99, 8", 
    dynArr.buffer[0] == 5 
    && dynArr.buffer[1] == 99
    && dynArr.buffer[2] == 8
  );
}

void testGetIndexFromDynamicArray() {
  int initialCapacity = 2;
  DynamicArray dynArr = init(initialCapacity);

  pushBack(&dynArr, 5);
  pushBack(&dynArr, 6);
  pushBack(&dynArr, 8);

  ASSERT_TEST("When pushing back 5, 6, 8 in dynamic array and getting index of element with value 6, the result should be equal to 1", 
    getIndex(&dynArr, 6) == 1
  );
  printf("%d", getIndex(&dynArr, 6));
}

int main(void) {
  testDynamicArrayInitializationWithCapacityDifferentThanZero();
  testPushingBackElementsInDynamicArray();

  testPushElementsInDynamicArray();
  testPushingBackElementsInDynamicArray();
  testPushFrontElementsInDynamicArray();
  
  testPopElementsInDynamicArray();
  testPopBackElementsInDynamicArray();
  testPopFrontElementsInDynamicArray();

  testGetElementFromDynamicArray();
  testSetElementFromDynamicArray();

  testGetIndexFromDynamicArray();

  return 0;
}