#include <stdio.h>
#include <stdlib.h>

int* addElToEnd(int arr[], int size) {
    int * temp = realloc(arr, size*sizeof(int));
    if(temp == NULL) {
        free(temp);
        printf("Error");
        exit(1);
    }
    printf("Add number:");
    scanf("%d", &temp[size-1]);
    return temp;
}

int* setNewSize(int arr[], int size) {
    int * temp = realloc(arr, size*sizeof(int));
    if(temp == NULL) {
        free(temp);
        printf("Error");
        exit(1);
    }
    return temp;
}

void printdynarr(int arr[], int size) {
    for(int i = 0; i< size; i++) {
        printf("El %d: %d\n", i+1, arr[i]);
    }
}

int main(void) {
    int size;
    printf("Enter number: ");
    scanf("%d", &size);
    int* arr = malloc(size * sizeof(int));
    if(arr == NULL) {
        free(arr);
        printf("Error");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int choice;
    do {
        printf("Menu\n");
        printf("1: Add element to the end\n");
        printf("2: Resize Array\n");
        printf("3: Print\n");
        printf("4: Exit\n");
        printf("Enter Choice:");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                size++;
                arr = addElToEnd(arr, size);
                break;
            case 2:
                printf("Set new size: ");
                scanf("%d", &size);
                arr = setNewSize(arr, size);
                break;
            case 3:
                printdynarr(arr, size);
                break;
            case 4:
                printf("exiting...\n");
                free(arr);
                break;
            default: 
                printf("Choice does not exist!\n");
        }
    } while(choice!=4);
    printf("Now ex.2:\n");

    int* arr3 = malloc(2 * sizeof(int));
    arr3[0] = 1;
    arr3[1] = 2;

    size = 2;

    size++;
    arr3 = addElToEnd(arr3, size);
    size++;
    arr3 = addElToEnd(arr3, size);
    size++;
    arr3 = addElToEnd(arr3, size);

    printdynarr(arr3, size);
    free(arr3);
}