#include <stdio.h>
#include <stdlib.h>

#define CHECK_ALLOC(ptr) \
    if ((ptr) == NULL) { \
        printf("Memory allocation error!\n"); \
        exit(1); \
    }

char* enterStr() {
    char current = '\0';
    char* line = NULL;
    size_t size = 0;

    do {
        current = getchar();
        size++;

        char* currentLine = realloc(line, size * sizeof(char));
        CHECK_ALLOC(currentLine);

        line = currentLine;
        line[size - 1] = current;

    } while (current != '\n' && size < 15);

    line[size - 1] = '\0';
    return line;
}

int main(void) {
    int c = 0;
    do {
        printf("Please enter the number of subjects: ");
        scanf("%d", &c);
    } while (c < 1);

    getchar();

    char** subjects = malloc(c * sizeof(char*));
    CHECK_ALLOC(subjects);

    for (int i = 0; i < c; i++) {
        printf("Enter subject %d: ", i + 1);
        subjects[i] = enterStr();
    }

    char** students = NULL;
    int** grades = NULL;
    int studentCount = 0;

    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Add student\n");
        printf("2. Print diary\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            studentCount++;

            students = realloc(students, studentCount * sizeof(char*));
            CHECK_ALLOC(students);

            grades = realloc(grades, studentCount * sizeof(int*));
            CHECK_ALLOC(grades);

            printf("Enter student name: ");
            students[studentCount - 1] = enterStr();

            grades[studentCount - 1] = malloc(c * sizeof(int));
            CHECK_ALLOC(grades[studentCount - 1]);

            for (int i = 0; i < c; i++) {
                printf("Enter grade for %s: ", subjects[i]);
                scanf("%d", &grades[studentCount - 1][i]);
                if (grades[studentCount - 1][i] < 2 || grades[studentCount - 1][i] > 6) {
                    printf("Enter grade for %s: ", subjects[i]);
                    scanf("%d", &grades[studentCount - 1][i]);
                }
            }
            getchar();

        } else if (choice == 2) {
            printf("\n%-15s", " ");

            for (int i = 0; i < c; i++) {
                printf("%-15s", subjects[i]);
            }
            printf("\n");

            for (int i = 0; i < studentCount; i++) {
                printf("%-15s", students[i]);
                for (int j = 0; j < c; j++) {
                    printf("%-15d", grades[i][j]);
                }
                printf("\n");
            }
        }

    } while (choice != 3);

    for (int i = 0; i < c; i++) {
        free(subjects[i]);
    }
    free(subjects);

    for (int i = 0; i < studentCount; i++) {
        free(students[i]);
        free(grades[i]);
    }

    free(students);
    free(grades);

    return 0;
}
