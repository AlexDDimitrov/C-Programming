#include "LinkedLists.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList init() {
  LinkedList linkedList = {
    .head = NULL,
    .size = 0
  };

  return linkedList;
}

static Node * createNode(ListType value) {
    Node * node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error allocating memory \n");
        exit(1);
    }

    node->value = value;
    node->next = NULL;

    return node;
}

void pushFront(LinkedList * list, ListType value) {
    Node * newNode = createNode(value);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

Node * getNode(LinkedList * list, uint index) {
    if (index >= list->size) {
        printf("Index out of bounds!");
        exit(1);
    }
    Node * current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

ListType get(LinkedList * list, uint index) {
    Node * node = getNode(list, index);
    return node->value;
}

void push(LinkedList * list, uint index, ListType value) {
    if (index > list->size) {
        printf("Index out of bounds!");
        exit(1);
    }

    if (index == 0) {
        pushFront(list, value);
    } else {
        Node * node = createNode(value);
        Node * prevNode = getNode(list, index-1);
        node->next = prevNode->next;
        prevNode->next = node;
        list->size++;
    }
}

void pushBack(LinkedList * list, ListType value) {
    return push(list, list->size, value);
}

ListType popFront(LinkedList * list) {
    if (list->size == 0) {
        printf("Cannot delete first element of empty list\n");
        exit(1);
    }
    Node * nodeToDelete = list->head;
    list->head = nodeToDelete->next;
    ListType result = nodeToDelete->value;
    free(nodeToDelete);
    list->size--;
    return result;
}

ListType pop(LinkedList * list, uint index) {
    if (index >= list->size) {
        printf("Index out of bounds!");
        exit(1);
    }

    if (index == 0) {
        return popFront(list);
    } else {
        Node * prevNode = getNode(list, index - 1);
        Node * nodeToDelete = prevNode->next;
        prevNode->next = nodeToDelete->next;

        ListType result = nodeToDelete->value;
        free(nodeToDelete);
        list->size--;
        return result;
    }
}

ListType popBack(LinkedList * list) {
    if (list->size == 0) {
        printf("Cannot pop from empty list\n");
        exit(1);
    }
    return pop(list, list->size - 1);
}

void set(LinkedList * list, uint index, ListType value) {    
    Node * node = getNode(list, index);
    node->value = value;
}

void release(LinkedList * list) {
    Node * current = list->head;
    while (current != NULL) {
        Node * next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->size = 0;
}