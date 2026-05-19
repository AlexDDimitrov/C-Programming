#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define TITLE_MAX 100
#define AUTHOR_MAX 100
#define GENRE_MAX 50
#define ISBN_MAX 20

typedef struct {
    char title[TITLE_MAX];
    char author[AUTHOR_MAX];
    char genre[GENRE_MAX];
    int year;
    char isbn[ISBN_MAX];
} Book;

typedef Book ListType;
typedef unsigned int uint;

typedef struct Node {
  ListType value;
  struct Node * next;
} Node;

typedef struct {
  Node * head;
  uint size;
} LinkedList;

LinkedList init();

void pushBack(LinkedList * list, ListType value);
void pushFront(LinkedList * list, ListType value);
void push(LinkedList * list, uint index, ListType value);

ListType popBack(LinkedList * list);
ListType popFront(LinkedList * list);
ListType pop(LinkedList * list, uint index);

Node * getNode(LinkedList * list, uint index);

ListType get(LinkedList * list, uint index);
void set(LinkedList * list, uint index, ListType value);

void release(LinkedList * list);

#endif