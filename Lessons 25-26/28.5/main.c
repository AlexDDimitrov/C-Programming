#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_STR 100

char currentFile[256];

void write(FILE* f, Person* c) {
    fwrite(c->egn, sizeof(char), 10, f);
    fwrite(&c->name_len, sizeof(unsigned char), 1, f);
    fwrite(c->name, sizeof(char), c->name_len, f);
    fwrite(&c->age, sizeof(unsigned char), 1, f);
    fwrite(&c->education, sizeof(char), 1, f);
    fwrite(&c->working, sizeof(char), 1, f);
    fwrite(&c->married, sizeof(char), 1, f);
}

int read(FILE* f, Person* c) {
    if (fread(c->egn, sizeof(char), 10, f) != 10)
        return 0;

    c->egn[10] = '\0';

    fread(&c->name_len, sizeof(unsigned char), 1, f);

    fread(c->name, sizeof(char), c->name_len, f);

    c->name[c->name_len] = '\0';

    fread(&c->age, sizeof(unsigned char), 1, f);
    fread(&c->education, sizeof(char), 1, f);
    fread(&c->working, sizeof(char), 1, f);
    fread(&c->married, sizeof(char), 1, f);

    return 1;
}

void add(FILE* file) {
    if (!file) {
        printf("No file opened.\n");
    } else {
        Person c;
        memset(&c, 0, sizeof(c));

        printf("EGN: ");
        fgets(c.egn, 11, stdin);
        if (c.egn[strlen(c.egn) - 1] == '\n') {
            c.egn[strlen(c.egn) - 1] = '\0';
        }
        getchar();

        getchar();

        printf("Name: ");
        fgets(c.name, MAX_NAME, stdin);

        c.name_len = strlen(c.name);

        if (c.name[c.name_len - 1] == '\n') {
            c.name[c.name_len - 1] = '\0';
            c.name_len--;
        }

        printf("Age: ");
        scanf("%u", &c.age);
        getchar();

        printf("Education (0=none, 1=basic, 2=middle, 3=high): ");
        scanf("%u", &c.education);
        getchar();

        printf("Working (0=no, 1=yes): ");
        scanf("%u", &c.working);
        getchar();

        printf("Married (0=no, 1=yes): ");
        scanf("%u", &c.married);
        getchar();

        write(file, &c);

        fflush(file);

        printf("Data added.\n");
    }
}

void print(FILE* file) {
    if (!file) {
        printf("No file opened.\n");
    } else {
        rewind(file);

        Person c;

        while (read(file, &c)) {

            printf("\nEGN: %s\n", c.egn);
            printf("Name: %s\n", c.name);
            printf("Age: %u\n", c.age);

            char educationStr[MAX_STR];

            switch (c.education) {
                case NONE:
                    strcpy(educationStr, "None");
                    break;

                case BASIC:
                    strcpy(educationStr, "Basic");
                    break;

                case MIDDLE:
                    strcpy(educationStr, "Middle");
                    break;

                case HIGH:
                    strcpy(educationStr, "High");
                    break;

                default:
                    strcpy(educationStr, "Unknown");
            }

            printf("Education: %s\n", educationStr);

            char workingStr[MAX_STR];

            switch (c.working) {
                case UNEMPLOYED:
                    strcpy(workingStr, "Unemployed");
                    break;

                case EMPLOYED:
                    strcpy(workingStr, "Employed");
                    break;

                default:
                    strcpy(workingStr, "Unknown");
            }

            printf("Working: %s\n", workingStr);

            char marriedStr[MAX_STR];

            switch (c.married) {
                case SINGLE:
                    strcpy(marriedStr, "Single");
                    break;

                case MARRIED:
                    strcpy(marriedStr, "Married");
                    break;

                default:
                    strcpy(marriedStr, "Unknown");
            }

            printf("Married: %s\n", marriedStr);
        }
    }
}

void delete(FILE* file) {
    if (!file) {
        printf("No file opened.\n");
    } else {
        char str[11];

        printf("EGN: ");
        fgets(str, 11, stdin);
        getchar();
        if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }

        int count = 0;

        Person temp;

        rewind(file);

        while (read(file, &temp)) {
            count++;
        }

        if (count == 0) {
            printf("File s empty.\n");
            return;
        }

        Person* list = malloc(count * sizeof(Person));

        if (!list) {
            printf("Memory alloc error.\n");
            return;
        }

        rewind(file);

        for (int i = 0; i < count; i++) {
            read(file, &list[i]);
        }

        int newCount = 0;
        int found = 0;

        for (int i = 0; i < count; i++) {

            if (strcmp(list[i].egn, str) != 0) {
                list[newCount++] = list[i];
            } else {
                found = 1;
            }
        }

        fflush(file);
        fclose(file);

        file = fopen(currentFile, "wb");

        if (!file) {
            printf("File error.\n");
            free(list);
            return;
        }

        for (int i = 0; i < newCount; i++) {
            write(file, &list[i]);
        }

        fclose(file);

        file = fopen(currentFile, "rb+");

        free(list);

        if (found)
            printf("EGN deleted.\n");
        else
            printf("EGN not found.\n");
    }
}

FILE * open() {

    printf("Enter filename: ");
    fgets(currentFile, 256, stdin);
    if (currentFile[strlen(currentFile) - 1] == '\n') {
        currentFile[strlen(currentFile) - 1] = '\0';
    }
    getchar();

    FILE * file = fopen(currentFile, "rb+");

    if (!file) {

        file = fopen(currentFile, "wb+");

        if (!file) {
            printf("Cannot make file.\n");
            return NULL;
        }

        printf("New file crated.\n");
    }
    else {
        printf("File opened.\n");
    }

    return file;
}

int main() {
    int choice;
    FILE * file = NULL;
    while (1) {
        printf("\nMENU\n");
        printf("1. Open file\n");
        printf("2. Add record\n");
        printf("3. Print all\n");
        printf("4. Delete by EGN\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: file = open(); break;
            case 2: add(file); break;
            case 3: print(file); break;
            case 4: delete(file); break;
            case 5: return 0;
            default: printf("Invalid.\n");
        }
    }
}
