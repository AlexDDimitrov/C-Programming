#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

void printMenu() {
    printf("\nDonor Management Menu\n");
    printf("1. Add donor (enter EGN)\n");
    printf("2. Remove donor by EGN\n");
    printf("3. Show all donors\n");
    printf("4. Exit\n");
    printf("Choice: ");
}

int main() {
    DynamicArray donors = init(2);
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            int egn;
            printf("Enter donor EGN: ");
            scanf("%d", &egn);

            pushBack(&donors, egn);
            printf("Donor added successfully.\n");
        }

        else if (choice == 2) {
            int egn;
            printf("Enter EGN to remove: ");
            scanf("%d", &egn);

            int index = getIndex(&donors, egn);
            if (index == -1) {
                printf("No donor found with this EGN.\n");
            } else {
                pop(&donors, index);
                printf("Donor removed successfully.\n");
            }
        }

        else if (choice == 3) {
            if (donors.size == 0) {
                printf("No donors registered.\n");
            } else {
                printf("List of donors:\n");
                for (uint i = 0; i < donors.size; i++) {
                    printf("%d\n", donors.buffer[i]);
                }
            }
        }

        else if (choice == 4) {
            printf("Exiting... Releasing resources.\n");
            release(&donors);
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
