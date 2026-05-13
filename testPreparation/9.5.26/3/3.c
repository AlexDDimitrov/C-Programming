#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef long arrType;

typedef struct Node {
    arrType value;
    struct Node * next;
} Node;

typedef struct Arr {
    Node * head;
    uint size;
} Arr;

Arr init() {
    Arr arr = {
        .head = NULL,
        .size = 0
    };

    return arr;
}

void check_alloc(void * ptr) {
    if (ptr == NULL) {
        printf("Error allocating memory!");
        exit(1);
    }
}

Node * createNode(arrType value) {
    Node * node = malloc(sizeof(Node));
    check_alloc(node);
    node->value = value;
    node->next = NULL;
    return node;
}

void pushFront(Arr * arr, arrType value) {
    Node * newNode = createNode(value);
    newNode->next = arr->head;
    arr->head = newNode;
    arr->size++;
}

void popFront(Arr * arr) {
    if (arr->size == 0) {
        printf("No elements have been added to the array");
        exit(1);
    }
    Node * nodeToDelete = arr->head;
    arr->head = nodeToDelete->next;
    free(nodeToDelete);
    arr->size--;
}

void printlinkedlist(Arr * arr) {
    Node * current = arr->head;
    while(current != NULL) {
        printf("%ld", current->value);
        current = current->next;
    }
    printf("\n");
}

int main () {
    Arr arr = init();
    pushFront(&arr, 1);
    pushFront(&arr, 2);
    pushFront(&arr, 3);
    printlinkedlist(&arr);
    popFront(&arr);
    popFront(&arr);
    printlinkedlist(&arr);
}