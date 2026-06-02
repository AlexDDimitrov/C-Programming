#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib-types.h"

#define FILENAME "books.csv"

void load(Book * books) {
    File * file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening the file!")
        save(books);
        exit(1);
    }
    
    char line[((MAX_LENGTH * 5) + 1)];
    int count = 0;

    while(fgets(&line, ((MAX_LENGTH * 5) + 1), file)) {
        count++;
    }

    rewind(file);
    books = malloc(count * sizeof(Book));
    int linei = 0;
    while(fgets(&line, ((MAX_LENGTH * 5) + 1), file)) {
        
        line[strcspn(&line, '\0')] = '\n';

        char* token = strtok(line, ',');
        if(token != NULL) {
            strcpy(books[linei].name, token);
        }

        token = strtok(NULL, ',');
        if(token != NULL) {
            strcpy(books[linei].author, token);
        }

        token = strtok(NULL, ',');
        if(token != NULL) {
            strcpy(books[linei].genre, token);
        }

        token = strtok(NULL, ',');
        if(token != NULL) {
            books[linei].year = atoi(token);
        }

        token = strtok(NULL, ',');
        if(token != NULL) {
            strcpy(books[linei].ISBN, token);
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
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;

    printf("Enter author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;

    printf("Enter genre: ");
    fgets(newBook.genre, sizeof(newBook.genre), stdin);
    newBook.genre[strcspn(newBook.genre, "\n")] = 0;

    printf("Enter year: ");
    scanf("%d", &newBook.year);

    printf("Enter ISBN: ");
    scanf("%s", newBook.isbn);

    books[(*bookCount)] = newBook;
    (*bookCount)++;
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
        printf("ISBN: %s\n", books[i].isbn);
        printf("\n");
    }
}

void delete(Book * books, int * bookCount) {
    char isbn[20];
    printf("Въведете ISBN за изтриване: ");
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
        printf("Book with ISBN %s not found.\n", isbn);
        return;
    }

    for (int i = foundIndex; i < (*bookCount) - 1; i++) {
        books[i] = books[i + 1];
    }
    (*bookCount)--;
}

void 

int main(void) {
    Book * books= NULL;
    int bookCount = 0;
    load(books, &bookCount);
    
    int choice;
    while (1) {
        printf("\nElectronic Library\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Delete Book by ISBN\n");
        printf("4. Save to File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(books, &bookCount); break;
            case 2: print(books, bookCount); break;
            case 3: delete(books, &bookCount); break;
            case 4: save(books, bookCount); break;
            case 5: stop(); break;
            default: printf("Invalid choice.\n");
        }

    }

    free(books);
    return 0;
}