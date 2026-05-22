#ifndef BOOK_H
#define BOOK_H

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

#endif