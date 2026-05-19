#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedLists.h"

typedef enum {
    false = 0,
    true = 1
} Boolean;

void loadFromFile(LinkedList * list, const char * filename) {
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error occurred while opening file!\n");
    } else {
        Book book;
        while (fscanf(file, "%s %s %s %d %s", book.title, book.author, book.genre, &book.year, book.isbn) == 5) {
            pushBack(list, book);
        }

        fclose(file);
    }
}

void saveToFile(LinkedList * list, const char * filename) {
    FILE * file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error occurred while writing to file!\n");
    } else {
        Node * current = list->head;
        while (current != NULL) {
            Book book = current->value;
            fprintf(file, "%s %s %s %d %s\n", book.title, book.author, book.genre, book.year, book.isbn);
            current = current->next;
            fflush(file);
        }

        fclose(file);
    }
}

void addBook(LinkedList * list) {
    Book book;

    printf("Enter book title: ");
    scanf("%s", book.title);

    printf("Enter author: ");
    scanf("%s", book.author);

    printf("Enter genre: ");
    scanf("%s", book.genre);

    printf("Enter year: ");
    scanf("%d", &book.year);

    printf("Enter ISBN: ");
    scanf("%s", book.isbn);

    pushBack(list, book);
    printf("Book added successfully!\n");
}

void printBooks(LinkedList * list) {
    if (list->size == 0) {
        printf("No books available.\n");
    } else {
        Node * current = list->head;
        int index = 1;

        while (current != NULL) {
            Book book = current->value;
            printf("\nBook %d:\n", index++);
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Genre: %s\n", book.genre);
            printf("Year: %d\n", book.year);
            printf("ISBN: %s\n", book.isbn);
            current = current->next;
        }
    }
}

void deleteByISBN(LinkedList * list) {
    if (list->size == 0) {
        printf("No books available for deletion.\n");
    } else {
        char isbn[20];
        printf("Enter ISBN for deletion: ");
        scanf("%s", isbn);

        Node * current = list->head;
        int index = 0;

        Boolean isfound = false;
        while (current != NULL) {
            Book book = current->value;
            if (strcmp(book.isbn, isbn) == 0) {
                pop(list, index);
                printf("Book deleted successfully!\n");
                isfound = true;
            }
            current = current->next;
            index++;
        }

        if (!isfound) {
            printf("No book found with the given ISBN.\n");
        }
    }
}

int main() {
    LinkedList library = init();
    const char * filename = "library.txt";

    loadFromFile(&library, filename);

    int choice;
    do {
        printf("\nLibrary Management\n");
        printf("1. Add book\n");
        printf("2. Display all books\n");
        printf("3. Delete book by ISBN\n");
        printf("4. Save to file\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(&library); break;
            case 2: printBooks(&library); break;
            case 3: deleteByISBN(&library); break;
            case 4: saveToFile(&library, filename); 
                    printf("File saved successfully!\n");
                    break;
            case 5: 
                    saveToFile(&library, filename);
                    printf("Exiting...\n");
                    break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);

    release(&library);
    return 0;
}