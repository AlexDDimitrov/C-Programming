#include <stdio.h>
#include "processes.h"

int main(void) {
    int choice;

    while (1) {
        printf("\n--- Task Manager ---\n");
        printf("1. Create process\n");
        printf("2. List processes\n");
        printf("3. Stop process\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1: {
            char name[30];
            printf("Enter process name: ");
            fgets(name, sizeof(name), stdin);

            for (int i = 0; name[i]; i++) {
                if (name[i] == '\n') {
                    name[i] = '\0';
                    break;
                }
            }

            int id = createnewprocess(name);
            if (id == 0) {
                printf("Error: maximum number of processes (5) reached.\n");
            } else {
                printf("Process created with ID: %d\n", id);
            }
            break;
        }

        case 2:
            if (processescount == 0) {
                printf("No running processes.\n");
            } else {
                for (int i = 0; i < processescount; i++) {
                    printf("ID: %d | Name: %s\n",
                           processes[i].id,
                           processes[i].name);
                }
            }
            break;

        case 3: {
            int id;
            printf("Enter ID of process to stop: ");
            scanf("%d", &id);
            stopprocess(id);
            break;
        }
        }
    }

    return 0;
}