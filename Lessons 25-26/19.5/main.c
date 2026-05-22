#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedLists.h"
#include "book.h"
#include "Boolean.h"

void loadFile(LinkedList * list, const char * filename) {
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file - R\n");
    } else {
        Book book;
        while (fscanf(file, "%s %s %s %d %s", book.title, book.author, book.genre, &book.year, book.isbn) == 5) {
            pushBack(list, book);
        }

        fclose(file);
    }
}

void saveFile(LinkedList * list, const char * filename) {
    FILE * file = fopen(filename, "w");
    if (file == NULL) {
        printf("Cannot open file - W\n");
    } else {
        Node * current = list->head;
        while (current != NULL) {
            Book book = current->value;
            fprintf(file, "%s %s %s %d %s\n", book.title, book.author, book.genre, book.year, book.isbn);
            current = current->next;
        }
        fflush(file);
        fclose(file);
    }
}

void addBook(LinkedList * list) {
    Book book;

    printf("Enter book title: ");
    //fgets(book.title, sizeof(book.title), stdin); - gave me a error
    scanf("%s", book.title);

    printf("Enter author: ");
    //fgets(book.author, sizeof(book.author), stdin);
    scanf("%s", book.author);

    printf("Enter genre: ");
    //fgets(book.genre, sizeof(book.genre), stdin);
    scanf("%s", book.genre);

    printf("Enter year: ");
    scanf("%d", &book.year);
    //getchar();

    printf("Enter ISBN: ");
    //fgets(book.isbn, sizeof(book.isbn), stdin);
    scanf("%s", book.isbn);

    pushBack(list, book);
}

void printList(LinkedList * list) {
    if (list->size == 0) {
        printf("No books in the library.\n");
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

void ISBN_delete(LinkedList * list) {
    if (list->size == 0) {
        printf("No books to delete.\n");
    } else {
        char isbn[20];
        printf("Enter ISBN: ");
        //fgets(isbn, sizeof(isbn), stdin);
        scanf("%s", isbn);

        Node * current = list->head;
        int index = 0;

        Boolean isfound = false;
        while (current != NULL) {
            if (strcmp(current->value.isbn, isbn) == 0) {
                pop(list, index);
                printf("Book deleted\n");
                isfound = true;
            }
            current = current->next;
            index++;
        }

        if (!isfound) {
            printf("No books found\n");
        }
    }
}

int main() {
    LinkedList library = init();
    const char * filename = "library.txt";

    loadFile(&library, filename);

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
        //getchar();

        switch (choice) {
            case 1: addBook(&library); break;
            case 2: printList(&library); break;
            case 3: ISBN_delete(&library); break;
            case 4: saveFile(&library, filename); 
                    printf("File saved\n");
                    break;
            case 5: 
                    saveFile(&library, filename);
                    printf("Exiting...\n");
                    break;
            default: printf("Invalid choice\n");
        }

    } while (choice != 5);

    release(&library);
    return 0;
}