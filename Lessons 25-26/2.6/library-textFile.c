#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib-types.h"

#define FILENAME "books.csv"

void save(Book * books, int bookCount) {
    File * file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening the file for writing!");
        exit(1);
    }

    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%s,%s,%s,%d,%s\n", books[i].title, books[i].author, books[i].genre, books[i].year, books[i].isbn);
    }
    fflush(file);
    fclose(file);
}

void load(Book * books, int * bookCount) {
    File * file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening the file!");
        save(books, *bookCount);
        exit(1);
    }
    
    char line[((MAX_LENGTH * 5) + 1)];
    int count = 0;

    char trash[((MAX_LENGTH * 5) + 1)];
    while(fgets(trash, ((MAX_LENGTH * 5) + 1), file)) {
        count++;
    }

    rewind(file);
    books = malloc(count * sizeof(Book));
    int linei = 0;
    while(fgets(line, ((MAX_LENGTH * 5) + 1), file)) {
        
        line[strcspn(line, '\0')] = '\n';

        char* token = strtok(line, ",");
        if(token != NULL) {
            strcpy(books[linei].title, token);
        }

        token = strtok(NULL, ",");
        if(token != NULL) {
            strcpy(books[linei].author, token);
        }

        token = strtok(NULL, ",");
        if(token != NULL) {
            strcpy(books[linei].genre, token);
        }

        token = strtok(NULL, ",");
        if(token != NULL) {
            books[linei].year = atoi(token);
        }

        token = strtok(NULL, ",");
        if(token != NULL) {
            strcpy(books[linei].isbn, token);
        }

        linei++;
    }

    printf("Loaded %d books from file.\n", count);
    fclose(file);
}

void add(Book * books, int * bookCount) {
    Book * temp = realloc(books, ((*bookCount) + 1) * sizeof(Book));
    if (temp == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    books = temp;

    Book newBook;

    printf("Enter book title: ");
    getchar();
    fgets(newBook.title, MAX_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;

    printf("Enter author: ");
    fgets(newBook.author, MAX_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;

    printf("Enter genre: ");
    fgets(newBook.genre, MAX_LENGTH, stdin);
    newBook.genre[strcspn(newBook.genre, "\n")] = 0;

    printf("Enter year: ");
    scanf("%d", &newBook.year);

    printf("Enter isbn: ");
    scanf("%s", newBook.isbn);

    books[(*bookCount)] = newBook;
    (*bookCount)++;

    save(books, *bookCount);
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

void delete(Book * books, int * bookCount) {
    char isbn[20];
    printf("Въведете isbn за изтриване: ");
    scanf("%s", isbn);
    getchar();

    int foundIndex = -1;
    for (int i = 0; i < (*bookCount); i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Book with isbn %s not found.\n", isbn);
        return;
    }

    for (int i = foundIndex; i < (*bookCount) - 1; i++) {
        books[i] = books[i + 1];
    }
    (*bookCount)--;
}

void stop(Book * books, int bookCount) {
    printf("Exiting the program\n");
    save(books, bookCount);
    exit(0);
}

int main(void) {
    Book * books= NULL;
    int bookCount = 0;
    load(books, &bookCount);
    
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
        getchar();

        switch (choice) {
            case 1: add(books, &bookCount); break;
            case 2: print(books, bookCount); break;
            case 3: delete(books, &bookCount); break;
            case 4: save(books, bookCount); break;
            case 5: stop(books, bookCount); break;
            default: printf("Invalid choice.\n");
        }

    }

    free(books);
    return 0;
}

//ADD DYNAMIC ARRAY OR LINKED LIST TO FIX ERRORSs