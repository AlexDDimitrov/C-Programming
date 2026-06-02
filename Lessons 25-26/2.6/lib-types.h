#ifndef LIB_TYPES_H
#define LIB_TYPES_H

#define MAX_LENGTH 255
typedef FILE File;

typedef struct Book {
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int year;
    char isbn[MAX_LENGTH];
} Book;

#endif