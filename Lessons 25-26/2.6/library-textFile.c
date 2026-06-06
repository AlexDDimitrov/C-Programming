#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib-types.h"

#define FILENAME "books.csv"

void check_alloc(void * ptr) {
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void save(Book * books, int bookCount) {
    File * file = fopen(FILENAME, "w");
    check_alloc(file);

    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%s,%s,%s,%d,%s\n", books[i].title, books[i].author, books[i].genre, books[i].year, books[i].isbn);
    }
    fflush(file);
    fclose(file);
}

Book * load(Book * books, int * bookCount) {
    File * file = fopen(FILENAME, "r");
    check_alloc(file);
    
    char line[(MAX_LENGTH * 4) + sizeof(int) + 10];
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        count++;
    }

    rewind(file);

    if (count == 0) {
        *bookCount = 0;
        return NULL;
    }

    books = malloc(count * sizeof(Book));
    check_alloc(books);
    *bookCount = count;

    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        line[strcspn(line, "\r")] = 0;

        char *token = strtok(line, ",");
        strcpy(books[i].title, token);

        token = strtok(NULL, ",");
        strcpy(books[i].author, token);

        token = strtok(NULL, ",");
        strcpy(books[i].genre, token);

        token = strtok(NULL, ",");
        books[i].year = atoi(token);

        token = strtok(NULL, ",");
        strcpy(books[i].isbn, token);

        i++;
    }

    fclose(file);
    return books;
}

Book * add(Book * books, int * bookCount) {
    Book * temp = realloc(books, (*bookCount + 1) * sizeof(Book));
    check_alloc(temp);

    books = temp;
    Book * b = &books[*bookCount];

    while (getchar() != '\n');
    printf("Enter book title: ");
    fgets(b->title, MAX_LENGTH, stdin);
    b->title[strcspn(b->title, "\n")] = 0;

    printf("Enter author: ");
    fgets(b->author, MAX_LENGTH, stdin);
    b->author[strcspn(b->author, "\n")] = 0;

    printf("Enter genre: ");
    fgets(b->genre, MAX_LENGTH, stdin);
    b->genre[strcspn(b->genre, "\n")] = 0;

    printf("Enter year: ");
    scanf("%d", &b->year);

    printf("Enter isbn: ");
    scanf("%s", b->isbn);

    (*bookCount)++;
    save(books, *bookCount);

    return books;
}

void print(Book * books, int bookCount) {
    if (books == NULL) {
        printf("No books to display.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Genre: %s\n", books[i].genre);
        printf("Year: %d\n", books[i].year);
        printf("isbn: %s\n", books[i].isbn);
        printf("\n");
    }
}

Book * delete(Book * books, int * bookCount) {
    char isbn[20];
    printf("Enter isbn for deletion: ");
    scanf("%s", isbn);
    while (getchar() != '\n');

    int foundIndex = -1;
    for (int i = 0; i < (*bookCount); i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Book with isbn %s not found.\n", isbn);
        return books;
    }

    for (int i = foundIndex; i < (*bookCount) - 1; i++) {
        books[i] = books[i + 1];
    }
    (*bookCount)--;
    books = realloc(books, (*bookCount) * sizeof(Book));
    return books;
}

void stop(Book * books, int bookCount) {
    printf("Exiting the program\n");
    save(books, bookCount);
    exit(0);
}

int main(void) {
    Book * books= NULL;
    int bookCount = 0;
    books = load(books, &bookCount);

    books = load(books, &bookCount);
    if (books == NULL) {
        books = malloc(0);
    }
    
    int choice;
    while (1) {
        printf("\nElectronic Library\n");
        printf("1. Add\n");
        printf("2. Print\n");
        printf("3. Delete\n");
        printf("4. Save\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1: books = add(books, &bookCount); break;
            case 2: print(books, bookCount); break;
            case 3: books = delete(books, &bookCount); break;
            case 4: save(books, bookCount); break;
            case 5: stop(books, bookCount); break;
            default: printf("Invalid choice.\n");
        }

    }

    free(books);
    return 0;
}