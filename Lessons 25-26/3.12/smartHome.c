#include <stdio.h>

int main() {
    printf("Smart Home System\n");

    short stop = 1;
    unsigned char lightsStatus = 0; 

    while (stop) {
        printf("\n1. Switch Lights\n");
        printf("2. Print State\n");
        printf("3. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int room;
            printf("Enter room number (1-8): ");
            scanf("%d", &room);

            if (room < 1 || room > 8) {
                printf("Invalid room number!\n");
                break;
            }


            lightsStatus ^= (1 << (room - 1));
            printf("Room %d light switched.\n", room);
            break;
        }

        case 2: {
            printf("The light is on in rooms: ");
            int any = 0;

            for (int i = 0; i < 8; i++) {
                if (lightsStatus & (1 << i)) {
                    printf("%d ", i + 1);
                    any = 1;
                }
            }

            if (!any)
                printf("none");

            printf("\n");
            break;
        }

        case 3:
            stop = 0;
            break;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
