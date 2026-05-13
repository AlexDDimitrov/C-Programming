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
    nodeToDelete->next = NULL;
    nodeToDelete->value = 0;
    free(nodeToDelete);
    arr->size--;
}

void printlinkedlist(Arr * arr) {
    Node * node = arr->head;
    while(node != NULL) {
        printf("%ld, ", node->value);
        node = node->next;
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

void in_bounds(Arr * arr, uint index) {
    if (index >= arr->size) {
        printf("Index out of bounds!");
        exit(1);
    }
}

Node * getNode(Arr * arr, uint index) {
    in_bounds(arr, index);
    Node * searched = arr->head;
    for(uint i = 0; i < index; i++) {
        searched = searched->next;
    }
    return searched;
} 

void push(Arr* arr, arrType value, uint index) {
    if(index == 0) {
        pushFront(arr, value);
    }
    else {
        Node * prev = getNode(arr, index-1);
        Node * newNode = createNode(value);
        newNode -> next = prev ->next;
        prev->next = newNode;
        arr->size++;
    }
}

void pushBack(Arr * arr, arrType value) {
    push(arr, value, arr->size);
}

void pop(Arr * arr, uint index) {
    if(index == 0) {
        popFront(arr);
    }
    else {
        Node * prevNode = getNode(arr, index - 1);
        Node * nodeToDelete = prevNode->next;
        prevNode->next = nodeToDelete->next;
        free(nodeToDelete);
        arr->size--;
    }
}

void popBack(Arr * arr) {
    pop(arr, arr->size-1);
}

void set(Arr * arr, uint index, arrType value) {
    Node * node = getNode(arr, index);
    node->value = value;
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