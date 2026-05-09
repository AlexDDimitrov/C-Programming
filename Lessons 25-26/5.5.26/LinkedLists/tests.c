#include <stdio.h>
#include "LinkedLists.h"

#define ASSERT_TEST(MESSAGE, CONDITION) \
  if (CONDITION) { \
    printf(MESSAGE ": PASSED\n"); \
  } else { \
    printf(MESSAGE ": FAILED\n"); \
  }

void printLinkedList(LinkedList * linkedList) {
    Node * current = linkedList->head;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("]\n");
}

void linkedListShouldBeInitializedCorrectly() {
  LinkedList linkedList = init();
  ASSERT_TEST("Empty linked list head should point to NULL", linkedList.head == NULL);
  ASSERT_TEST("Empty linked list size should be equal to 0", linkedList.size == 0);
}

void pushingOneElementInEmptyLinkedListShouldWorkCorrectly() {
  LinkedList linkedList = init();
  pushFront(&linkedList, 5);

  ASSERT_TEST("New size should be equal to 1", linkedList.size == 1);
  ASSERT_TEST("First element should have correct value", linkedList.head->value == 5);
}

void getShouldWorkCorrectly() {
  LinkedList linkedList = init();
  pushFront(&linkedList, 5);
  pushFront(&linkedList, 10);
  pushFront(&linkedList, 15);

  int value1 = get(&linkedList, 0);
  ASSERT_TEST("First element should have correct value", value1 == 15);

  int value2 = get(&linkedList, 1);
  ASSERT_TEST("Second element should have correct value", value2 == 10);

  int value3 = get(&linkedList, 2);
  ASSERT_TEST("Third element should have correct value", value3 == 5);
}

void pushBackShouldWorkCorrectly() {
  LinkedList list = init();
  pushBack(&list, 1);
  pushBack(&list, 2);
  pushBack(&list, 3);

  ASSERT_TEST("Size should be 3", list.size == 3);
  ASSERT_TEST("Last element should be 3", get(&list, 2) == 3);
}

void pushAtIndexShouldWorkCorrectly() {
  LinkedList list = init();
  pushBack(&list, 1);
  pushBack(&list, 3);
  push(&list, 1, 2);

  ASSERT_TEST("Size should be 3", list.size == 3);
  ASSERT_TEST("Middle element should be 2", get(&list, 1) == 2);
}

void popFrontShouldWorkCorrectly() {
  LinkedList list = init();
  pushBack(&list, 10);
  pushBack(&list, 20);

  int removed = popFront(&list);

  ASSERT_TEST("Removed element should be 10", removed == 10);
  ASSERT_TEST("New head should be 20", list.head->value == 20);
  ASSERT_TEST("Size should be 1", list.size == 1);
}

void popBackShouldWorkCorrectly() {
  LinkedList list = init();
  pushBack(&list, 10);
  pushBack(&list, 20);
  pushBack(&list, 30);

  int removed = popBack(&list);

  ASSERT_TEST("Removed element should be 30", removed == 30);
  ASSERT_TEST("New last element should be 20", get(&list, 1) == 20);
  ASSERT_TEST("Size should be 2", list.size == 2);
}

void popAtIndexShouldWorkCorrectly() {
  LinkedList list = init();
  pushBack(&list, 10);
  pushBack(&list, 20);
  pushBack(&list, 30);

  int removed = pop(&list, 1);

  ASSERT_TEST("Removed element should be 20", removed == 20);
  ASSERT_TEST("New element at index 1 should be 30", get(&list, 1) == 30);
  ASSERT_TEST("Size should be 2", list.size == 2);
}

void setShouldWorkCorrectly() {
  LinkedList list = init();
  pushBack(&list, 10);
  pushBack(&list, 20);

  set(&list, 1, 99);

  ASSERT_TEST("Value at index 1 should be updated to 99", get(&list, 1) == 99);
}

void releaseShouldFreeAllNodes() {
  LinkedList list = init();
  pushBack(&list, 1);
  pushBack(&list, 2);
  pushBack(&list, 3);

  release(&list);

  ASSERT_TEST("List size should be 0 after release", list.size == 0);
  ASSERT_TEST("List head should be NULL after release", list.head == NULL);
}

int main(void) {

  linkedListShouldBeInitializedCorrectly();
  pushingOneElementInEmptyLinkedListShouldWorkCorrectly();
  getShouldWorkCorrectly();
  pushBackShouldWorkCorrectly();
  pushAtIndexShouldWorkCorrectly();
  popFrontShouldWorkCorrectly();
  popBackShouldWorkCorrectly();
  popAtIndexShouldWorkCorrectly();
  setShouldWorkCorrectly();
  releaseShouldFreeAllNodes();

  return 0;
}

