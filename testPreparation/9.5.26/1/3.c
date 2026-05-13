#include <stdio.h>
#include <stdlib.h>

typedef long arrType;
typedef unsigned int uint;

typedef struct Node {
    arrType value;
    struct Node * next;
} Node;

typedef struct Arr {
    uint size;
    Node * head;
} Arr;

Arr init() {
    Arr newArr = {
        .head = NULL,
        .size = 0
    };

    return newArr;
}

Node * createNode(arrType value) {
    Node * node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void pushFront (Arr * arr, arrType value) {
    Node * node = createNode(value);
    node->next = arr->head;
    arr->head = node;
    arr->size++;
}

void popFront (Arr * arr) {
    if (arr->size == 0) {
        printf("Cannot pop from empty array\n");
        exit(1);
    }
    Node * nodeToDelete = arr->head;
    arr->head = nodeToDelete->next;
    free(nodeToDelete);
    arr->size--;
}

void printlinkedlist(Arr * arr) {
    Node * current = arr->head;
    while (current != NULL) {
        printf("%ld ", current->value);
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

/////////////////////////
//допълнително за упражнение:

Node * getNode(Arr * arr, uint index) {
    if (index >= arr->size) {
        printf("Error index out of bounds");
        exit(1);
    }
    Node * searched = arr->head;
    for (int i = 0; i < index; i++) {
        searched = searched->next;
    }
    return searched;
}

void push(Arr * arr, arrType value, uint index) {
    if (index > arr->size) {
        printf("Index out of bounds!");
        exit(1);
    }
    if (index == 0) {
        pushFront(arr, value);
    } else {
        Node * node = getNode(arr, index - 1);
        Node * newNode = createNode(value);
        newNode -> next = node -> next;
        node -> next = newNode;
        arr -> size++;
    }
}

void pushback(Arr * arr, arrType value) {
    push(arr, value, arr->size);
}

void pop(Arr * arr, uint index) {
    if (arr->size == 0) {
        printf("Cannot delete first element of empty list\n");
        exit(1);
    }

    if (index == 0) {
        popFront(arr);
    } else {
        Node * prevNode = getNode(arr, index - 1);
        Node * nodeToDelete = prevNode->next;
        prevNode->next = nodeToDelete->next;
        free(nodeToDelete);
        arr->size--;
    }
}

void popBack(Arr * arr) {
    return pop(arr, arr->size - 1);
}

void set(Arr * arr, arrType value, uint index) {
    Node * node = getNode(arr, index);
    node -> value = value;
}

void release(Arr * arr) {
    Node * current = arr->head;
    while (current != NULL) {
        Node * next = current->next;
        free(current);
        current = next;
    }
    arr->head = NULL;
    arr->size = 0;
}