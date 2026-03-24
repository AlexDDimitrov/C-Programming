#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[16];
    int number;
    double grade;
} Student;

int main(void) {
    Student* students = NULL;
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Add student\n");
        printf("2. Print students\n");
        printf("3. Exit\n");
        printf("Pick: ");
        scanf("%d", &choice);

        if (choice == 1) {
            students = realloc(students, (count) * sizeof(Student));
             if (!students) {
                printf("Error allocating memory!\n");
                return 1;
            }

            char name[15];
            int number;
            double grade;
            printf("Name enyer: ");
            scanf("%s", name);

            printf("Number in class: ");
            scanf("%d", &number);

            printf("Enter avr grade: ");
            scanf("%lf", &grade);

            strcpy(students[count].name, name);
            students[count].number = number;
            students[count].grade = grade; 

            printf("Student has been added succesfullu\n");
            count++;
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("No students found!!\n");
            } else {
                printf("\n---- Students ---\n");
                for (int i = 0; i < count; i++) {
                    printf("Name: %15s : Number: %3d : Avr grade: %.2f\n",
                           students[i].name,
                           students[i].number,
                           students[i].grade);
                }
            }
        }
        else if (choice == 3) {
            printf("Exiting...");
            break;
        }
        else {
            printf("Not a valid choice!\n");
        }
    }

    free(students);
    return 0;
}